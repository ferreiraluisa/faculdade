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
using namespace std;

class scene{
    public:
      scene();
      void render();
      void set_color(float r,float g,float b);
      //add
      void set_ortho2d(float left,float right,float bottom,float top);
    private:
      GLuint VBO;
      GLuint ShaderProgram;
      float color[3];
      //add
      float ortho2d_values[4];

};

scene::scene(){
   const char* pVSFileName = "../src/shader.vs";
   const char* pFSFileName = "../src/shader.fs";
   ShaderProgram = CompileShaders(pVSFileName,pFSFileName);
   CreateVertexBufferTriangle(VBO);
   color[0] = 1.0;
   color[1] = color[2] = 0.0;
   //add
   ortho2d_values[0] = -1.0;
   ortho2d_values[1] = 1.0;
   ortho2d_values[2] = -1.0;
   ortho2d_values[3] = 1.0;
}

void scene::render(){
    glUseProgram(ShaderProgram);
    GLint color_u = glGetUniformLocation(ShaderProgram,"Color");
    glUniform3fv(color_u,1,color);
    //add
    GLint ortho2d_u = glGetUniformLocation(ShaderProgram,"ortho2d");
    glUniform4fv(ortho2d_u,1,ortho2d_values);
    GLint atributo = glGetAttribLocation(ShaderProgram,"Position");
    glEnableVertexAttribArray(atributo);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(atributo, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
   
}

void scene::set_color(float r,float g,float b){
  color[0] = r;
  color[1] = g;
  color[2] = b;
  return;
}

//add
void scene::set_ortho2d(float left,float right,float bottom,float top){
  ortho2d_values[0] = left;
  ortho2d_values[1] = 2.0/(right - left);
  ortho2d_values[2] = bottom;
  ortho2d_values[3] = 2.0/(top - bottom);
  return;
}


#endif