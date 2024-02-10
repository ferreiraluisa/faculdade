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
#include "shadow_map.h"

struct LightProperties {
   bool is_camera_coordinate;
   bool isEnabled;
   bool isLocal;
   bool isSpot;
   glm::vec3 ambient;
   glm::vec3 color;
   glm::vec3 position;
   glm::vec3 coneDirection;
   float spotCosCutoff;
   float spotExponent;
   float constantAttenuation;
   float linearAttenuation;
   float quadraticAttenuation;
};


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
      void set_light(int light_number, LightProperties my_light);
      void push_back_object(object *new_object);
      void push_back_objects(vector<object*> new_objects);
      void set_Viewport(int X0,int Y0,int Width, int Height);
    private:
      GLuint ShaderProgram;
      glm::mat4 Projection_matrix;
      glm::mat4 View;
      vector<object*> my_objects;      
      LightProperties lights[8];
      const int MaxLights = 8;
      int ViewportX0,ViewportY0,ViewportWidth, ViewportHeight;  

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

   for(int i=1;i < MaxLights;i++)
      lights[i].isEnabled = false;
      
   lights[0].is_camera_coordinate = true;
   lights[0].isEnabled = true;
   lights[0].isLocal = true;
   lights[0].isSpot = false;

   lights[0].ambient[0] = lights[0].ambient[1] = lights[0].ambient[2] = 0.3;
   lights[0].color[0] = lights[0].color[1] = lights[0].color[2] = 1.0;
   lights[0].position[0] =  0.0;
   lights[0].position[1] = 5.0;
   lights[0].position[2] = 0.0;
   
   lights[0].constantAttenuation = 1.0;
   lights[0].linearAttenuation = 0.0;
   lights[0].quadraticAttenuation = 0.0;
   ViewportX0 = 0;
   ViewportY0 = 0;
   ViewportWidth = 800;
   ViewportHeight = 800;
   

}

void scene::push_back_object(object *new_object){
   my_objects.push_back(new_object);
}

void scene::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glUseProgram(ShaderProgram);
    GLint color_u = glGetUniformLocation(ShaderProgram,"Color");
    GLint mvp_u = glGetUniformLocation(ShaderProgram,"MVPMatrix");
    GLint mv_u = glGetUniformLocation(ShaderProgram,"MVMatrix");
    GLint normal_u = glGetUniformLocation(ShaderProgram,"NormalMatrix");
    
    GLint position = glGetAttribLocation(ShaderProgram,"Position");
   
    glEnableVertexAttribArray(position);
    GLint normal = glGetAttribLocation(ShaderProgram,"Normal");
    glEnableVertexAttribArray(normal);

    GLint texcoord = glGetAttribLocation(ShaderProgram,"TexCoord");
    glEnableVertexAttribArray(texcoord);

    //Light 
    for(int i = 0;i < MaxLights;i++){
        string light_name = "Lights[" + std::to_string(i) + "]";
        GLint isEnabled_u = glGetUniformLocation(ShaderProgram,(light_name + ".isEnabled").c_str() );
        GLint isLocal_u = glGetUniformLocation(ShaderProgram,(light_name + ".isLocal").c_str() );
        GLint isSpot_u = glGetUniformLocation(ShaderProgram,(light_name + ".isSpot").c_str() );
        GLint ambient_u = glGetUniformLocation(ShaderProgram,(light_name + ".ambient").c_str() );
        GLint lightcolor_u = glGetUniformLocation(ShaderProgram,(light_name + ".color").c_str() );
        GLint lightposition_u = glGetUniformLocation(ShaderProgram,(light_name + ".position").c_str() );
       
        GLint constantAttenuation_u = glGetUniformLocation(ShaderProgram,(light_name + ".constantAttenuation").c_str() );
        GLint linearAttenuation_u = glGetUniformLocation(ShaderProgram,(light_name + ".linearAttenuation").c_str() );
        GLint quadraticAttenuation_u = glGetUniformLocation(ShaderProgram,(light_name + ".quadraticAttenuation").c_str() );

        glUniform1i(isEnabled_u,lights[i].isEnabled);
        glUniform1i(isLocal_u,lights[i].isLocal);
        glUniform1i(isSpot_u,lights[i].isSpot);
        glUniform3fv(ambient_u,1,glm::value_ptr(lights[i].ambient));
        glUniform3fv(lightcolor_u,1,glm::value_ptr(lights[i].color));
        
        //TODO: TEST is_camera_coordinate and isLocal
        glUniform3fv(lightposition_u,1,glm::value_ptr(lights[i].position));

        //TODO: INCLUDE OTHER Light Properties
        
        glUniform1f(constantAttenuation_u,lights[i].constantAttenuation);
        glUniform1f(linearAttenuation_u,lights[i].linearAttenuation);
        glUniform1f(quadraticAttenuation_u,lights[i].quadraticAttenuation);

    }

    
    //Material
    GLint shininess_u = glGetUniformLocation(ShaderProgram,"Shininess");
    GLint strength_u = glGetUniformLocation(ShaderProgram,"Strength");
    GLint texture_combiner_u = glGetUniformLocation(ShaderProgram,"Texture_combiner");

    GLint gSampler = glGetUniformLocation(ShaderProgram, "gSampler");
    //TEXTURE0 is difuse color
    glUniform1i(gSampler, 0);
    

    for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
    { 
        glUniform1f(shininess_u,(**it).Shininess);
        glUniform1f(strength_u,(**it).Strength);
        glUniform1i(texture_combiner_u,(**it).Texture_combiner);

        glUniform3fv(color_u,1,(**it).color);
        glUniformMatrix4fv(mvp_u,1,GL_FALSE,glm::value_ptr(Projection_matrix*View*((**it).Model_matrix))); 
        glUniformMatrix4fv(mv_u,1,GL_FALSE,glm::value_ptr(View*((**it).Model_matrix))); 
        glUniformMatrix3fv(normal_u,1,GL_FALSE,glm::value_ptr(glm::inverseTranspose(glm::mat3(View*((**it).Model_matrix)))));
        (**it).render(position,normal,texcoord);

    }
  
    
}

void scene::set_color(float r,float g,float b){
  for (auto it = my_objects.begin(); it != my_objects.end(); ++it)
  { 
      (**it).set_color(r,g,b);
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

void scene::set_light(int light_number, LightProperties my_light){
          if (light_number >= MaxLights || light_number < 0)
             return;
          lights[light_number] = my_light;
          return;      
   
}

void scene::set_Viewport(int X0,int Y0,int Width, int Height){
  ViewportX0 = X0;
  ViewportY0 = Y0,
  ViewportWidth = Width;
  ViewportWidth = Height;
}

#endif