#ifndef SCENE_H__
#define SCENE_H__

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "utils.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
using namespace std;

class scene{
    public:
      scene();
      void render();
      void set_color(float r,float g,float b);
      //add
      void set_ortho2d(float left,float right,float bottom,float top);
      void set_modelview(glm::mat4 model);
    private:
      GLuint VBO;
      GLuint EBO;
      int v_num;
      int i_num;
      GLuint ShaderProgram;
      float color[3];
      //add
      glm::mat4 ortho2d_matrix;
      glm::mat4 model_matrix;

};

scene::scene(){
   const char* pVSFileName = "../src/shader.vs";
   const char* pFSFileName = "../src/shader.fs";
   ShaderProgram = CompileShaders(pVSFileName,pFSFileName);
   CreateVertexBufferTriangle(VBO, EBO, v_num, i_num);
   color[0] = 1.0;
   color[1] = color[2] = 0.0;
   //add
   ortho2d_matrix = glm::mat4(1.0);
   model_matrix = glm::mat4(1.0);

}

void scene::render(){
    glUseProgram(ShaderProgram);
    GLint color_u = glGetUniformLocation(ShaderProgram,"Color");
    glUniform3fv(color_u,1,color);
    //add
    GLint ortho2d_u = glGetUniformLocation(ShaderProgram,"ortho2d");
    glUniformMatrix4fv(ortho2d_u,1,GL_FALSE,glm::value_ptr(ortho2d_matrix));
    GLint model_u = glGetUniformLocation(ShaderProgram,"model");
    glUniformMatrix4fv(model_u,1,GL_FALSE,glm::value_ptr(model_matrix));
    GLint atributo = glGetAttribLocation(ShaderProgram,"Position");
    glEnableVertexAttribArray(atributo);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glVertexAttribPointer(atributo, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawElements(GL_TRIANGLES, i_num, GL_UNSIGNED_SHORT, 0);
   
}

void scene::set_color(float r,float g,float b){
  color[0] = r;
  color[1] = g;
  color[2] = b;
  return;
}

//add
void scene::set_ortho2d(float left,float right,float bottom,float top){
  glm::mat4 t1 = glm::translate(glm::mat4(1.0), glm::vec3(-left,-bottom,0.0));
  glm::mat4 s = glm::scale(glm::mat4(1.0), glm::vec3(2.0/(right-left),2.0/(top-bottom),1.0));
  glm::mat4 t2 = glm::translate(glm::mat4(1.0), glm::vec3(-1.0,-1.0,0.0));

  ortho2d_matrix = t2*s*t1;
  return;
}

void scene::set_modelview(glm::mat4 model){
  model_matrix = model;
  return;
}


#endif