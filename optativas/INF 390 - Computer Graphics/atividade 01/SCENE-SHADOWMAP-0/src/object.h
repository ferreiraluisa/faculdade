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
#include "texture.h"

class scene;
class object{
   public:
      friend class scene;
      object(int v_number,int i_number, GLfloat *Vertices_information,GLushort *index);
      ~object(); 
      void set_color(float r,float g,float b);
      void set_shininess(float shininess){Shininess = shininess;};
      void set_texture_combiner(int texture_combiner){Texture_combiner = texture_combiner;use_texture= texture_combiner>0?true:false;};
      void set_strength(float strength){Strength = strength;};
      void set_use_texture(bool Use_texture) {use_texture = use_texture;};
      void load_texture2D_simple_bmp(const char * name,int header_size,int Width,int Height,int BGR);
      void Model(glm::mat4 model_matrix);
      void push_right_matrix(glm::mat4 matrix);
      void push_left_matrix(glm::mat4 matrix);
      glm::mat4 get_Model_matrix();
      void set_wireframe(bool on_wireframe){wireframe =  on_wireframe;};
      friend class scene;
   private:
      void render(GLint position,GLint normal,GLint texcoord);
      bool indexed;
      bool wireframe;
      bool no_normal;
      bool no_texture;
      float color[3];
      float Shininess;
      float Strength;
      bool use_texture;

      glm::mat4 Model_matrix;
      GLuint VBO;
      GLuint EBO;
      int v_number;
      int i_number;
      Texture *my_texture;
      //0 NO TEXTURE, 1 REPLACE, 2 MODULATE
      int Texture_combiner;
};
object::~object(){
   glDeleteBuffers(1, &VBO);
   if(indexed)
     glDeleteBuffers(1, &EBO);
}
object::object(int v_number,int i_number, GLfloat *Vertices_information,GLushort *index):v_number(v_number),i_number(i_number){
   indexed = true;
   wireframe = false; 
   no_normal = false;
   no_texture = false;
   use_texture = false;
   Texture_combiner = 0;
   glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*v_number*8, Vertices_information, GL_STATIC_DRAW);
 	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)*i_number, index, GL_STATIC_DRAW);
   color[0] = 1.0;
   color[1] = color[2] = 0.0;
   Shininess = 50.0;
   Strength = 1.0;
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

void object::render(GLint position,GLint normal,GLint texcoord){
   if(no_normal){
      if(no_texture){
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
      //TODO: if (no_texture == false) ...
   }else{
      if(no_texture){
         glBindBuffer(GL_ARRAY_BUFFER, VBO);
         glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
         glVertexAttribPointer(normal, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
      
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
      else{
         glBindBuffer(GL_ARRAY_BUFFER, VBO);
         glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
         glVertexAttribPointer(normal, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
         glVertexAttribPointer(texcoord, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6* sizeof(float)));
         if(use_texture)
            my_texture->Bind(GL_TEXTURE0);

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
   }

}

void object::load_texture2D_simple_bmp(const char * name,int header_size,int Width,int Height,int BGR=0){
   if(no_texture){
      cout << "Object without uv " << endl;
      exit(1);
   }
   my_texture = new Texture(GL_TEXTURE_2D,name);
   my_texture->Load_simple_bmp(header_size,Width,Height,BGR);
   use_texture = true;
}

#endif