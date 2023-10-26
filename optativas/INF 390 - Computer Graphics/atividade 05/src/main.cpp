#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>

#include "scene.h"
#include "object.h"
#include "loadobject.h"

using namespace std;
 
bool color[4][4] = {0};
bool ortho_per = true;
GLint width = 800,height = 800; 

int ombrox=0, ombroy=0, ombroz=0;
int cotoveloz=0,maox=0,dedoz=0;

 
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}



static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if ( key == GLFW_KEY_P && action == GLFW_PRESS ) 
        ortho_per = true;
    if ( key == GLFW_KEY_O && action == GLFW_PRESS ) 
       ortho_per = false;
    if(action == GLFW_PRESS){
        switch (key)
        {
        case GLFW_KEY_Q:
            if (mods == GLFW_MOD_SHIFT) {
                ombrox = (ombrox + 5)%360;
            }
            else {
                ombrox = (ombrox - 5)%360;
            }
            break;
        case GLFW_KEY_W:
            if (mods == GLFW_MOD_SHIFT) {
                ombroy = (ombroy + 5)%360;
            }
            else {
                ombroy = (ombroy - 5)%360;
            }
            break;
        case GLFW_KEY_E:
            if (mods == GLFW_MOD_SHIFT) {
                ombroz = (ombroz + 5)%360;
            }
            else {
                ombroz = (ombroz - 5)%360;
            }
            break;
        case GLFW_KEY_A:
            if (mods == GLFW_MOD_SHIFT) {
                cotoveloz = cotoveloz + 5;
                if(cotoveloz > 120 ) cotoveloz = 120;
            }
            else {
                cotoveloz = cotoveloz - 5;
                if(cotoveloz < -120 ) cotoveloz = -120;
            }
            break;
        case GLFW_KEY_S:
            if (mods == GLFW_MOD_SHIFT) {
                maox = (maox + 5)%360;
            }
            else {
                maox = (maox - 5)%360;
            }
            break;
        case GLFW_KEY_D:
            if (mods == GLFW_MOD_SHIFT) {
                dedoz = dedoz + 5;
                if(dedoz > 90 ) dedoz = 90;
            }
            else {
                dedoz = dedoz - 5;
                if(dedoz < 0 ) dedoz = 0;
            }
            break;
        default:
            break;
        }

    }

}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        color[(int)(xpos/(width/4))][3 - (int)(ypos/(height/4))] = !(color[(int)(xpos/(width/4))][3 - (int)(ypos/(height/4))]);

    }
        
}
void framebuffer_size_callback(GLFWwindow* window, int new_width, int new_height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    width = new_width;
    height = new_height;
    glMatrixMode(GL_MODELVIEW);
}

int main(void)
{
    GLFWwindow* window; 
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
 
    window = glfwCreateWindow(width, height, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
 
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
  
    glEnable(GL_DEPTH_TEST);
    scene my_scene;
    vector<object*> braco;

    object *cubo = read_obj_file("../models/cubo.obj");
    object *esfera = read_obj_file("../models/esfera.obj");

    braco.push_back(read_obj_file("../models/esfera.obj"));
    braco.push_back(read_obj_file("../models/cubo.obj"));
    braco.push_back(read_obj_file("../models/esfera.obj"));
    braco.push_back(read_obj_file("../models/cubo.obj"));
    braco.push_back(read_obj_file("../models/esfera.obj"));
    braco.push_back(read_obj_file("../models/cubo.obj"));
    braco.push_back(read_obj_file("../models/cubo.obj"));
    braco.push_back(read_obj_file("../models/esfera.obj"));
    braco.push_back(read_obj_file("../models/cubo.obj"));
    braco.push_back(read_obj_file("../models/esfera.obj"));
    braco.push_back(read_obj_file("../models/cubo.obj"));

    my_scene.push_back_objects(braco);
    my_scene.set_wireframe(true);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    my_scene.LookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);

    while (!glfwWindowShouldClose(window))
    {
        glViewport(0, 0,width , height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        if (ortho_per){
           my_scene.perspective(0.75,1.0,0.1,200.0);
        }else{
           my_scene.Ortho3D(-2.0,2.0,-2.0,2.0,0.0,200.0);
        }
        glm::mat4 matrix_now = glm::rotate(glm::rotate(glm::rotate(glm::mat4(1.0f),glm::radians((float)ombrox),glm::vec3(1.0f,0.0f,0.0f)), glm::radians((float)ombroy),glm::vec3(0.0f,1.0f,0.0f)), glm::radians((float)ombroz),glm::vec3(0.0f,0.0f,1.0f));

        braco[0]->Model(matrix_now); //esfera
        glm::mat4 matrix_aux = glm::scale(glm::translate(glm::mat4(1.0), glm::vec3(2.0,0.0,0.0)),glm::vec3(2.0f,0.8f,0.8f));
        braco[1]->Model(matrix_now*matrix_aux); //a escala tem que acontecer ANTES da rotação global, então ela tem que estar a direita no cálculo da multiplicação, cubo

        matrix_now = matrix_now * glm::scale(glm::translate(glm::mat4(1.0), glm::vec3(4.0,0.0,0.0)), glm::vec3(0.8f,0.8f,0.8f));
        matrix_now = glm::rotate(matrix_now, glm::radians((float)cotoveloz),glm::vec3(0.0f,0.0f,1.0f));
        braco[2]->Model(matrix_now); //esfera
        matrix_aux = glm::scale(glm::translate(glm::mat4(1.0), glm::vec3(2.0,0.0,0.0)),glm::vec3(2.0f,0.7f,0.7f));
        braco[3]->Model(matrix_now*matrix_aux); //cubo

        matrix_now = matrix_now * glm::scale(glm::translate(glm::mat4(1.0), glm::vec3(4.0,0.0,0.0)), glm::vec3(0.7f,0.7f,0.7f));
        matrix_now = glm::rotate(matrix_now, glm::radians((float)maox),glm::vec3(1.0f,0.0f,0.f));
        braco[4]->Model(matrix_now); //esfera
        matrix_aux = glm::scale(glm::rotate(glm::translate(glm::mat4(1.0), glm::vec3(1.0, 1.0, 0.0)), glm::radians(float(45%360)), glm::vec3(0.0f, 0.0f, 5.0f)), glm::vec3(2.0f, 0.7f, 0.7f));
        braco[5]->Model(matrix_now * matrix_aux); // cubo
        matrix_aux = glm::scale(glm::rotate(glm::translate(glm::mat4(1.0), glm::vec3(1.0, -1.0, 0.0)), glm::radians(float(-45%360)), glm::vec3(0.0f, 0.0f, 1.0f)), glm::vec3(2.0f, 0.7f, 0.7f));
        braco[6]->Model(matrix_now * matrix_aux); // cubo

        glm::mat4 aux = glm::scale(glm::translate(matrix_now, glm::vec3(2.5, 2.5, 0.0)), glm::vec3(0.9f, 0.9f, 0.9f));
        aux = glm::rotate(aux, glm::radians((float)-dedoz), glm::vec3(0.0f, 0.0f, 1.0f));
        braco[7]->Model(aux); // esfera
        matrix_aux = glm::scale(glm::rotate(glm::translate(glm::mat4(1.0), glm::vec3(1.2f, 1.2f, 0.0f)), glm::radians(float(45%360)), glm::vec3(0.0,0.0,1.0)), glm::vec3(1.2f, 0.7f, 0.7f));
        braco[8]->Model(aux * matrix_aux); // cubo


        aux = glm::scale(glm::translate(matrix_now, glm::vec3(2.5, -2.5, 0.0)), glm::vec3(0.9f, 0.9f, 0.9f));
        aux = glm::rotate(aux, glm::radians((float)dedoz), glm::vec3(0.0f, 0.0f, 1.0f));
        braco[9]->Model(aux); // esfera
        matrix_aux = glm::scale(glm::rotate(glm::translate(glm::mat4(1.0), glm::vec3(1.2, -1.2, 0.0)), glm::radians(float(-45%360)), glm::vec3(0.0,0.0,1.0)), glm::vec3(1.2f, 0.7f, 0.7f));
        braco[10]->Model(aux * matrix_aux); // cubo

        // cout<<width<<""<<height<<endl;
        my_scene.render();              
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}