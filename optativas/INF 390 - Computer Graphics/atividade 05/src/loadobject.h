#ifndef LOAD_H__
#define LOAD_H__
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include "utils.h"
using namespace std;
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "object.h"
#include "scene.h"

vector<object*> DefineCubo(scene *my_scene){
      GLfloat vertices[8*3] = {
         0.5,0.5,0.5,
        -0.5,0.5,0.5,
        -0.5,-0.5,0.5,
         0.5,-0.5,0.5,
         0.5,0.5,-0.5,
        -0.5,0.5,-0.5,
        -0.5,-0.5,-0.5,
         0.5,-0.5,-0.5,
      };
     GLushort face1[6] = {0,1,2,0,2,3};
     GLushort face2[6] = {6,5,4,7,6,4};
     GLushort face3[6] = {0,4,5,0,5,1};
     GLushort face4[6] = {3,2,6,3,6,7};
     GLushort face5[6] = {0,3,7,0,7,4};
     GLushort face6[6] = {1,5,6,1,6,2};
     object *o_f1 = new object(8,6,vertices,face1);
     object *o_f2 = new object(8,6,vertices,face2);
     object *o_f3 = new object(8,6,vertices,face3);
     object *o_f4 = new object(8,6,vertices,face4);
     object *o_f5 = new object(8,6,vertices,face5);
     object *o_f6 = new object(8,6,vertices,face6);
      
     o_f1->set_color(1.0,0.0,0.0);
     o_f2->set_color(1.0,0.0,0.0);
     o_f3->set_color(0.0,1.0,0.0);
     o_f4->set_color(0.0,1.0,0.0);
     o_f5->set_color(0.0,0.0,1.0);
     o_f6->set_color(0.0,0.0,1.0);
    
     if(my_scene != NULL){
        my_scene->push_back_object(o_f1);
        my_scene->push_back_object(o_f2);
        my_scene->push_back_object(o_f3);
        my_scene->push_back_object(o_f4);
        my_scene->push_back_object(o_f5);
        my_scene->push_back_object(o_f6);
     }
     vector<object*> cubo;
     cubo.push_back(o_f1);
     cubo.push_back(o_f2);
     cubo.push_back(o_f3);
     cubo.push_back(o_f4);
     cubo.push_back(o_f5);
     cubo.push_back(o_f6);
     return cubo;
}

object* read_obj_file(string filename){
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        throw std::ios_base::failure("Error opening file: " + filename);
    }
    vector<GLfloat> position;
    vector<GLfloat> normal;
    vector<GLfloat> uv;
    vector<GLushort> index_position;
    vector<GLushort> index_normal;
    vector<GLushort> index_uv;
    std::string line;
    while (std::getline(file, line)) {
         std::istringstream iss(line);
         std::string token;
         iss >> token;
         if (token == "v") {
            float x,y,z;
            iss >> x >> y >> z;
            position.push_back(x);
            position.push_back(y);
            position.push_back(z);
            //cout << "v " << x << " " << y << " " << z << endl;
        } else if (token == "vn") {
            float nx,ny,nz;
            iss >> nx >> ny >> nz;
            normal.push_back(nx);
            normal.push_back(ny);
            normal.push_back(nz);
            //cout << "vn " << nx << " " << ny << " " << nz << endl;
        } else if (token == "vt") {
            float u,v;
            iss >> u >> v;
            uv.push_back(u);
            uv.push_back(v);
            //cout << "vt " << u << " " << v << endl;
        } else if (token == "f") {
            //cout << "f ";
            for (int i = 0; i < 3; ++i) {
            uint32_t index_v,index_n,index_u; 
            iss >> index_v;
            //cout << index_v;
            index_position.push_back(index_v - 1);
            if (iss.peek() == '/') {
                iss.ignore();
                //cout << '/';
               if (iss.peek() != '/') {
                    iss >> index_u;
                    //cout << index_u;
                    index_uv.push_back(index_u -1);
                }
                if (iss.peek() == '/') {
                   //cout << '/';
                    iss.ignore();
                    iss >> index_n;
                    //cout << index_n;
                    index_normal.push_back(index_n -1);
                }
                }
                //cout << " ";
            }
                //cout << endl;
        }
    }        
    file.close();
    object *my_obj = new object(position.size()/3,index_position.size(),position.data(),index_position.data());
    return my_obj;

}




#endif