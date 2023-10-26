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

using namespace std;
 
bool color[4][4] = {0};
GLint width = 800,height = 800; 

 
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
 //global
bool ortho_per = false;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if ( key == GLFW_KEY_P && action == GLFW_PRESS )
        ortho_per = true;
    if ( key == GLFW_KEY_O && action == GLFW_PRESS )
        ortho_per = false;
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


void DesenhaCubo(scene *my_scene){
    GLfloat vertices[24] = {
    0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f, 0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f
    };
    GLushort face1[6] = {0, 1, 2, 2, 3, 0};
    GLushort face2[6] = {6, 5, 4, 7, 6, 4};
    GLushort face3[6] = {0, 4, 5, 0, 5, 1};
    GLushort face4[6] = {7, 3, 2, 6, 7, 2};
    GLushort face5[6] = {0, 3, 7, 0, 7, 4};
    GLushort face6[6] = {2, 1, 5, 2, 5, 6};

    object *f1 = new object(8,6,vertices,face1);
    f1->set_color(1.0f, 0.0f, 0.0f);  // red

    object *f2 = new object(8,6,vertices,face2);
    f2->set_color(1.0f, 0.0f, 0.0f);  

    object *f3 = new object(8,6,vertices,face3);
    f3->set_color(0.0f, 1.0f, 0.0f);  // green

    object *f4 = new object(8,6,vertices,face4);
    f4->set_color(0.0f, 1.0f, 0.0f);  

    object *f5 = new object(8,6,vertices,face5);
    f5->set_color(0.0f, 0.0f, 1.0f);  // blue

    object *f6 = new object(8,6,vertices,face6);
    f6->set_color(0.0f, 0.0f, 1.0f); 

    my_scene->push_back_object(f1);
    my_scene->push_back_object(f2);
    my_scene->push_back_object(f3);
    my_scene->push_back_object(f4);
    my_scene->push_back_object(f5);
    my_scene->push_back_object(f6);

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
    glFrontFace(GL_CW);
    scene my_scene;
    DesenhaCubo(&my_scene);
    
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    my_scene.lookAt(3.0f,1.5f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    glViewport(0, 0,width , height);
  
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (ortho_per){
            my_scene.perspective(0.75,1.0,0.1,100.0);
        }else{
            my_scene.Ortho3D(-2.0,2.0,-2.0,2.0,0.0,10.0);
        }
        my_scene.render();              
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}