#ifndef SCENE_H__
#define SCENE_H__

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "utils.h"
using namespace std;
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "object.h"

class scene{
    public:
      scene();
      ~scene();
      void render();
      void set_color(float r,float g,float b);
      void Ortho3D(float WL,float WR,float WB, float WT,float zNear,float zFar);
      void perspective(float fovy, float aspect, float zNear, float zFar);
      void LookAt(float eyex,float eyey,float eyez,
                  float centerx,float centery,float centerz,
                  float upx,float upy,float upz);
      void Model(glm::mat4 model_matrix);
      void push_back_object(object *new_object);
      void push_back_objects(vector<object*> new_objects);
      void set_wireframe(bool on_wireframe);
    private:
      GLuint ShaderProgram;
      glm::mat4 Projection_matrix;
      glm::mat4 View;
      vector<object*> my_objects;

};
scene::~scene(){
  for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
  { 
     delete (*it);
  }
}

scene::scene(){
   const char* pVSFileName = "../src/shader.vs";
   const char* pFSFileName = "../src/shader.fs";
   ShaderProgram = CompileShaders(pVSFileName,pFSFileName);
   Projection_matrix = glm::mat4(1.0);
   View = glm::mat4(1.0);
}

void scene::push_back_object(object *new_object){
   my_objects.push_back(new_object);
}

void scene::render(){
    glUseProgram(ShaderProgram);
    GLint color_u = glGetUniformLocation(ShaderProgram,"Color");
    GLint projection_u = glGetUniformLocation(ShaderProgram,"Projection");
    GLint model_u = glGetUniformLocation(ShaderProgram,"Model");
    GLint view_u = glGetUniformLocation(ShaderProgram,"View");
    GLint position = glGetAttribLocation(ShaderProgram,"Position");
    glEnableVertexAttribArray(position);

    for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
    { 
        glUniform3fv(color_u,1,(**it).color);
        glUniformMatrix4fv(projection_u,1,GL_FALSE,glm::value_ptr(Projection_matrix)); 
        glUniformMatrix4fv(view_u,1,GL_FALSE,glm::value_ptr(View)); 
        glUniformMatrix4fv(model_u,1,GL_FALSE,glm::value_ptr(((**it).Model_matrix)));
        (**it).render(position);
    }
  
    
}

void scene::set_color(float r,float g,float b){
  for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
  { 
      (**it).set_color(r,g,b);
  }
  return;
}

void scene::set_wireframe(bool on_wireframe){
  for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
  { 
      (**it).set_wireframe(true);
  }
  return;
}

void scene::Ortho3D(float WL,float WR,float WB, float WT,float zNear, float zFar){
    
    Projection_matrix = glm::ortho(
WL, WR,
WB, WT,
zNear, zFar);

    return;
}

void scene::Model(glm::mat4 model_matrix){
    for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
    { 
      (**it).push_left_matrix(model_matrix);
    }
    return;
}

void scene::LookAt(float eyex,float eyey,float eyez,
                  float centerx,float centery,float centerz,
                  float upx,float upy,float upz){

    View = glm::lookAt(
       glm::vec3(eyex,eyey,eyez),
       glm::vec3(centerx,centery,centerz),
       glm::vec3(upx,upy,upz));

}

void scene::perspective(float fovy, float aspect, float zNear, float zFar){
  Projection_matrix = glm::perspective(fovy,aspect, zNear, zFar);
}

void scene::push_back_objects(vector<object*> new_objects){
     for (auto it = new_objects.begin(); it != new_objects.end(); ++it)
     {
        my_objects.push_back(*it);
     }
}

#endif