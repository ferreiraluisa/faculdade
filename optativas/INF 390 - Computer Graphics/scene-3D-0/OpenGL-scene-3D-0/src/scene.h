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
      void Ortho2D(float WL,float WR,float WB, float WT);
      void Model(glm::mat4 model_matrix);
      void push_back_object(object *new_object);
    private:
      GLuint ShaderProgram;
      glm::mat4 Ortho2D_matrix;
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
   Ortho2D_matrix = glm::mat4(1.0);
}

void scene::push_back_object(object *new_object){
   my_objects.push_back(new_object);
}

void scene::render(){
    glUseProgram(ShaderProgram);
    GLint color_u = glGetUniformLocation(ShaderProgram,"Color");
    GLint ortho2d_u = glGetUniformLocation(ShaderProgram,"Ortho2D");
    GLint model_u = glGetUniformLocation(ShaderProgram,"Model");
    GLint atributo = glGetAttribLocation(ShaderProgram,"Position");
    glEnableVertexAttribArray(atributo);

    for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
    { 
        glUniform3fv(color_u,1,(**it).color);
        glUniformMatrix4fv(ortho2d_u,1,GL_FALSE,glm::value_ptr(Ortho2D_matrix));  
        glUniformMatrix4fv(model_u,1,GL_FALSE,glm::value_ptr(((**it).Model_matrix)));
        glBindBuffer(GL_ARRAY_BUFFER, (**it).VBO);
        glVertexAttribPointer(atributo, 3, GL_FLOAT, GL_FALSE, 0, 0);
        if(!((**it).indexed)){
           glDrawArrays(GL_TRIANGLES, 0, (**it).v_number);
        }else{
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (**it).EBO);
            glDrawElements(GL_TRIANGLES,(**it).i_number,GL_UNSIGNED_SHORT,NULL);
        }
    }
  
    
}

void scene::set_color(float r,float g,float b){
  for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
  { 
      (**it).set_color(r,g,b);
  }
  return;
}

void scene::Ortho2D(float WL,float WR,float WB, float WT){
    glm::mat4 t1 = glm::translate(glm::mat4(1.0),glm::vec3(-WL,-WB,0.0));
    glm::mat4 s = glm::scale(glm::mat4(1.0),glm::vec3(2.0/(WR - WL),2.0/(WT - WB),1.0));
    glm::mat4 t2 = glm::translate(glm::mat4(1.0),glm::vec3(-1.0,-1.0,0.0));
 
    Ortho2D_matrix = t2*s*t1;

    return;
}

void scene::Model(glm::mat4 model_matrix){
    for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
    { 
      (**it).Model(model_matrix);
    }
    return;
}

#endif