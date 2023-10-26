#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "scene.h"
using namespace std;
GLint width = 800,height=800; 
//add
bool color[4][4] = {{0}};
//add
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        color[int(xpos / (width / 4))][3 - int(ypos / (height / 4))] = !color[int(xpos / (width / 4))][3 - int(ypos / (height / 4))];
    }
}
//teste para ajustar a janela e funcionou :) (https://www.glfw.org/docs/3.3/window_guide.html#framebuffer_size)
void framebuffer_size_callback(GLFWwindow* window, int new_width, int new_height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Aqui você pode ajustar a matriz de projeção de acordo com o novo tamanho da janela.
    width = new_width;
    height = new_height;
    glMatrixMode(GL_MODELVIEW);
}



static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
 
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
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
    //add
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

 
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
  
    
    scene my_scene;

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        //add
        glClear(GL_COLOR_BUFFER_BIT);
        for(int i = 0; i < 4; i ++ ){
            for(int j = 0; j < 4; j++){
                if(color[i][j])
                    my_scene.set_color(1.0,0.0,0.0);
                else
                    my_scene.set_color(1.0,1.0,0.0);
                glViewport((width/4)*i, (height/4)*j, (width/4), (height/4));
                my_scene.set_ortho2d(1.0, -1.0, 1.0, -1.0);
                my_scene.render();        
                glViewport((width/4)*i, (height/4)*j, (width/4), (height/4));
                my_scene.set_ortho2d(-1.0, 1.0, -1.0, 1.0);
                my_scene.render();
            }
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}