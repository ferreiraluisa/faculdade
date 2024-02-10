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
GLint width = 800,height = 800; 

int worldx=0, worldy=0, worldz=0;
float camerax=0.0,cameray=2.0,cameraz=8.0;

void set_light_default(LightProperties &light){
   light.is_camera_coordinate = true;
   light.isEnabled = true;
   light.isLocal = true;
   light.isSpot = false;

   light.ambient[0] = light.ambient[1] = light.ambient[2] = 0.3;
   light.color[0] = light.color[1] = light.color[2] = 1.0;
   light.position[0] =  0.0;
   light.position[1] = 5.0;
   light.position[2] = 0.0;
   
   light.constantAttenuation = 1.0;
   light.linearAttenuation = 0.0;
   light.quadraticAttenuation = 0.0;
   return;
}

 
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
    
    LightProperties light0,light1;
    set_light_default(light0); 
    
    my_scene.set_light(0,light0);
    //my_scene.set_light(1,light1);

    vector<object*> objetos;
    objetos.push_back(read_obj_file("../models/esfera_sm.obj"));
    objetos[0]->set_color(0.5,0.5,0.5);
    objetos[0]->load_texture2D_simple_bmp("../models/lena.bmp",122,256,256);
    objetos[0]->set_texture_combiner(2);

    objetos.push_back(read_obj_file("../models/esfera_sm.obj"));
    objetos[1]->set_color(0.5,0.5,0.5);
    objetos[1]->load_texture2D_simple_bmp("../models/texture.bmp",138,1000,500);
    objetos[1]->set_texture_combiner(1);

    objetos.push_back(read_obj_file("../models/cubo.obj"));
    objetos[2]->set_color(1.0,0.5,0.5);
    objetos[2]->set_texture_combiner(0);
    

    my_scene.push_back_object(objetos[0]);
    my_scene.push_back_object(objetos[1]);
    my_scene.push_back_object(objetos[2]);

    
    
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    my_scene.set_Viewport(0, 0,width , height);
    

    while (!glfwWindowShouldClose(window))
    {
        if (ortho_per){
           my_scene.perspective(0.75,1.0,0.1,200.0);
        }else{
           my_scene.Ortho3D(-2.0,2.0,-2.0,2.0,0.0,200.0);
        }

        my_scene.LookAt(camerax,cameray,cameraz,0.0,0.0,0.0,0.0,1.0,0.0);
        
        glm::mat4 matrix_now = glm::rotate(glm::rotate(glm::rotate(glm::mat4(1.0),glm::radians((float)worldx),glm::vec3(1.0,0.0,0.0)),glm::radians((float)worldy),glm::vec3(0.0,1.0,0.0)),glm::radians((float)worldz),glm::vec3(0.0,0.0,1.0));
        objetos[0]->Model(matrix_now);

        matrix_now = glm::scale(glm::mat4(1.0),glm::vec3(10.0,10.0,10.0));
        objetos[1]->Model(matrix_now);

        matrix_now = scale(glm::translate(glm::mat4(1.0),glm::vec3(0.0,-2.0,0.0)),glm::vec3(10.0,0.1,10.0));
        objetos[2]->Model(matrix_now);

        my_scene.render();              
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}