#ifndef TEXTURE_H__
#define TEXTURE_H__

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


class Texture
{
    public:
        friend class scene;
        Texture(GLenum TextureTarget, const std::string& FileName);
        bool Load_simple_bmp(int header_size,int Width,int Height,int BGR);
        void Bind(GLenum TextureUnit);
    private:
        
        std::string m_fileName;
        GLenum m_textureTarget;
        GLuint m_textureObj;
        int m_imageWidth = 0;
        int m_imageHeight = 0;
        int m_imageBPP = 0;
        void LoadInternal(void* image_data);
};

Texture::Texture(GLenum TextureTarget, const std::string& FileName)
{
    m_textureTarget = TextureTarget;
    m_fileName      = FileName;
}

bool Texture::Load_simple_bmp(int header_size,int Width,int Height,int BGR){
   GLubyte tex[Height][Width][3];
   try{
        ifstream arq(m_fileName,ios::binary);
        char c;
        if(!arq){
            cout << "Error ao abrir" << m_fileName;
            exit(1);
        }
        int i = 0;
        for(int i = 0; i < header_size ; i++)
            c = arq.get();
        for(int i = 0; i < Height ; i++)
            for(int j = 0; j < Width ; j++)
            {
                if(!(BGR)){
                    c = arq.get();
                    tex[i][j][2] = c;
                    c =  arq.get();
                    tex[i][j][1] = c ;
                    c =  arq.get();
                    tex[i][j][0] = c;
                }else{
                    c = arq.get();
                    tex[i][j][0] = c;
                    c =  arq.get();
                    tex[i][j][1] = c ;
                    c =  arq.get();
                    tex[i][j][2] = c;
                }
                
            }

        arq.close();
        arq.clear();
    }
    catch(...)
    {
        cout << "Erro ao ler imagem" << endl;
        return false;
    }
   
   
    m_imageWidth = Width;
    m_imageHeight = Height;
    m_imageBPP = 3;
    LoadInternal((void*)tex);
    return true;
}

void Texture::LoadInternal(void* image_data)
{
    glGenTextures(1, &m_textureObj);
    glBindTexture(m_textureTarget, m_textureObj);

    if (m_textureTarget == GL_TEXTURE_2D) {
        switch (m_imageBPP) {
        case 1:
            glTexImage2D(m_textureTarget, 0, GL_RED, m_imageWidth, m_imageHeight, 0, GL_RED, GL_UNSIGNED_BYTE, image_data);
            break;

        case 2:
            glTexImage2D(m_textureTarget, 0, GL_RG, m_imageWidth, m_imageHeight, 0, GL_RG, GL_UNSIGNED_BYTE, image_data);
            break;

        case 3:
            glTexImage2D(m_textureTarget, 0, GL_RGB, m_imageWidth, m_imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
            break;

        case 4:
            glTexImage2D(m_textureTarget, 0, GL_RGBA, m_imageWidth, m_imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
            break;

        }
    } else {
        printf("Support for texture target %x is not implemented\n", m_textureTarget);
        exit(1);
    }

    glTexParameteri(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(m_textureTarget, GL_TEXTURE_BASE_LEVEL, 0);
    glTexParameteri(m_textureTarget, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(m_textureTarget, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glGenerateMipmap(m_textureTarget);

    glBindTexture(m_textureTarget, 0);
}



void Texture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    glBindTexture(m_textureTarget, m_textureObj);
}

#endif