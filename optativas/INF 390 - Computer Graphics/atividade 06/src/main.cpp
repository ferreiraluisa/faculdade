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

bool ortho_per = true;
bool light_camera = true; //luz na coordenada da camera 
GLint width = 800,height = 800; 

int worldx=0, worldy=0, worldz=0;
float camerax=1.0,cameray=4.0,cameraz=5.0; //se modificar o x, y a iluminação fica diferente na coordenada do mundo

/*
APERTANDO C NO TECLADO MUDA A COORDENADA DA LUZ PARA A COORDENADA DA CAMERA
APERTANDO M NO TECLADO MUDA A COORDENADA DA LUZ PARA A COORDENADA DO MUNDO
*/
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
    if ( key == GLFW_KEY_C && action == GLFW_PRESS ) 
        light_camera = true;
    if ( key == GLFW_KEY_M && action == GLFW_PRESS ) 
       light_camera = false;
    if(action == GLFW_PRESS){
        switch (key)
        {
        case GLFW_KEY_Q:
            if (mods == GLFW_MOD_SHIFT) {
                worldx = (worldx + 5)%360;
            }
            else {
                worldx = (worldx - 5)%360;
            }
            break;
        case GLFW_KEY_W:
            if (mods == GLFW_MOD_SHIFT) {
                worldy = (worldy + 5)%360;
            }
            else {
                worldy = (worldy - 5)%360;
            }
            break;
        case GLFW_KEY_E:
            if (mods == GLFW_MOD_SHIFT) {
                worldz = (worldz + 5)%360;
            }
            else {
                worldz = (worldz - 5)%360;
            }
            break;
        case GLFW_KEY_A:
            if (mods == GLFW_MOD_SHIFT) {
                cameraz = cameraz + 0.1;
            }
            else {
                cameraz = cameraz - 0.1;
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
        //color[(int)(xpos/(width/4))][3 - (int)(ypos/(height/4))] = !(color[(int)(xpos/(width/4))][3 - (int)(ypos/(height/4))]);

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
    braco.push_back(read_obj_file("../models/esfera_sm.obj"));
    // braco[0]->set_wireframe(true);
    my_scene.push_back_object(braco[0]);
    
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);

    int screenWidth = videoMode->width;
    int screenHeight = videoMode->height;

    while (!glfwWindowShouldClose(window))
    {
        glViewport(0, 0,width , height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        if (ortho_per){
           my_scene.perspective(0.75,1.0,0.1,200.0);
        }else{
           my_scene.Ortho3D(-2.0,2.0,-2.0,2.0,0.0,200.0);
        }
        if(light_camera){
            my_scene.set_light_coordinate_system(true);
        }else{
            my_scene.set_light_coordinate_system(false);
        }
        
        my_scene.LookAt(camerax,cameray,cameraz,0.0,0.0,0.0,0.0,1.0,0.0);
        
        glm::mat4 matrix_now = glm::rotate(glm::rotate(glm::rotate(glm::mat4(1.0),glm::radians((float)worldx),glm::vec3(1.0,0.0,0.0)),glm::radians((float)worldy),glm::vec3(0.0,1.0,0.0)),glm::radians((float)worldz),glm::vec3(0.0,0.0,1.0));
        // matrix_now = glm::rotate(matrix_now, glm::radians(3.14f), glm::vec3(0.0, 0.0, 1.0));
        
        braco[0]->Model(matrix_now);
        my_scene.render();              
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}