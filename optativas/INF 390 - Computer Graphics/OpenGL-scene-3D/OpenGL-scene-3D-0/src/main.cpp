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
                maox = (maox + 5)%360;
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
    
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
  
    glEnable(GL_DEPTH_TEST);
    scene my_scene;
    vector<object*> cubo = DefineCubo(NULL);
    my_scene.push_back_objects(cubo);
    my_scene.set_wireframe(true);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glViewport(0, 0,width , height);
    my_scene.LookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        if (ortho_per){
           my_scene.perspective(0.75,1.0,0.1,200.0);
        }else{
           my_scene.Ortho3D(-2.0,2.0,-2.0,2.0,0.0,200.0);
        }
        
        my_scene.render();              
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}