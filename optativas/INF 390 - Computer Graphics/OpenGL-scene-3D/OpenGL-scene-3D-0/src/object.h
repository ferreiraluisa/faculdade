#ifndef OBJECT_H__
#define OBJECT_H__

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "utils.h"
using namespace std;
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class scene;
class object{
   public:
      friend class scene;
      object(); 
      object(int v_number, GLfloat *Vertices);
      object(int v_number,int i_number, GLfloat *Vertices,GLushort *index);
      ~object(); 
      void set_color(float r,float g,float b);
      void Model(glm::mat4 model_matrix);
      void push_right_matrix(glm::mat4 matrix);
      void push_left_matrix(glm::mat4 matrix);
      glm::mat4 get_Model_matrix();
      void set_wireframe(bool on_wireframe){wireframe =  on_wireframe;};
      friend class scene;
   private:
      void render(GLint position);
      bool indexed;
      bool wireframe;
      float color[3];
      glm::mat4 Model_matrix;
      GLuint VBO;
      GLuint EBO;
      int v_number;
      int i_number;

};
object::~object(){
   glDeleteBuffers(1, &VBO);
   if(indexed)
     glDeleteBuffers(1, &EBO);
}
object::object(){
   indexed = true;
   wireframe = false;
   CreateVertexBufferTriangle(VBO,EBO,v_number,i_number);
   color[0] = 1.0;
   color[1] = color[2] = 0.0;
   Model_matrix = glm::mat4(1.0);
};

object::object(int v_number, GLfloat *Vertices):v_number(v_number){
   indexed = false;
   wireframe = false;   
   glGenBuffers(1, &VBO);
   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*v_number*3, Vertices, GL_STATIC_DRAW);
   color[0] = 1.0;
   color[1] = color[2] = 0.0;
   Model_matrix = glm::mat4(1.0);
};

object::object(int v_number,int i_number, GLfloat *Vertices,GLushort *index):v_number(v_number),i_number(i_number){
   indexed = true;
   wireframe = false; 
   glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*v_number*3, Vertices, GL_STATIC_DRAW);
 	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)*i_number, index, GL_STATIC_DRAW);
    color[0] = 1.0;
    color[1] = color[2] = 0.0;
    Model_matrix = glm::mat4(1.0);
}

void object::set_color(float r,float g,float b){
  color[0] = r;
  color[1] = g;
  color[2] = b;
  return;
}

void object::Model(glm::mat4 model_matrix){
    Model_matrix = model_matrix;
    return;
}

void object::push_right_matrix(glm::mat4 matrix){
   Model_matrix = Model_matrix*matrix;
}
void object::push_left_matrix(glm::mat4 matrix){
   Model_matrix = matrix*Model_matrix;
}

glm::mat4 object::get_Model_matrix(){
   return Model_matrix;
}

void object::render(GLint position){
   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 0, 0);
   if(!wireframe){
      if(!(indexed)){
         glDrawArrays(GL_TRIANGLES, 0, v_number);
      }else{
         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
         glDrawElements(GL_TRIANGLES,i_number,GL_UNSIGNED_SHORT,NULL);
      }
   }else{
      glPolygonMode(GL_FRONT, GL_LINE);
      glPolygonMode(GL_BACK, GL_LINE);
      if(!(indexed)){
         glDrawArrays(GL_TRIANGLES, 0, v_number);
      }else{
         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
         glDrawElements(GL_TRIANGLES,i_number,GL_UNSIGNED_SHORT,NULL);
      }
      glPolygonMode(GL_FRONT, GL_FILL);
      glPolygonMode(GL_BACK, GL_FILL);
   }

}

#endif