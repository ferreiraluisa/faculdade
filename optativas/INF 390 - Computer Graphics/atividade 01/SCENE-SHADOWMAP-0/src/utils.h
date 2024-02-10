#ifndef UTILS_H__
#define UTILS_H__


#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;


GLchar *readTextFile(const char * name){
     FILE *fp;
     GLchar * content = NULL;
     int cont = 0;
     if(name == NULL)
        return NULL;
     fp = fopen(name,"rt");
     if(fp == NULL)
        return NULL;
     fseek(fp,0,SEEK_END);
     cont = ftell(fp);
     rewind(fp);
     if(cont> 0){
       content = (GLchar *) malloc(sizeof(char) * (cont +1));
       if(content != NULL){
          cont = fread(content,sizeof(char),cont,fp);
          content[cont] = '\0';

       }

     }

     fclose(fp);
     return content;

}

static void CreateVertexBufferTriangle(GLuint &VBO,GLuint &EBO,int &v_number,int &i_number)
{
    GLfloat Vertices[9][3]= {
    {0.0f, 0.0f, 0.0f}, 
    {-1.0f, 0.0f, 0.0f},
    {-0.7f, 0.7f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.7f, 0.7f, 0.0f},
    {1.0f, 0.0f, 0.0f},
    {0.7f, -0.7f, 0.0f},
    {0.0f, -1.0f, 0.0f},
    {-0.7f, -0.7f, 0.0f}
    };
 	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    v_number = 9;

    GLushort index[24]= {
     0,1,2,0,2,3,0,3,4,0,4,5,0,5,6,0,6,7,0,7,8,0,8,1
    };
 	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
    i_number = 24;
}

static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
    GLuint ShaderObj = glCreateShader(ShaderType);

    if (ShaderObj == 0) {
        fprintf(stderr, "Error creating shader type %d\n", ShaderType);
        exit(0);
    }

    const GLchar* p[1];
    p[0] = pShaderText;
    //cout << pShaderText;
    GLint Lengths[1];
    Lengths[0]= strlen(pShaderText);
    glShaderSource(ShaderObj, 1, p, Lengths);
    glCompileShader(ShaderObj);
    GLint success;
    glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
        exit(1);
    }

    glAttachShader(ShaderProgram, ShaderObj);
}

static GLuint CompileShaders(const char* pVSFileName, const char* pFSFileName)
{
    GLuint ShaderProgram = glCreateProgram();
    
    if (ShaderProgram == 0) {
        fprintf(stderr, "Error creating shader program\n");
        exit(1);
    }

    char * shv, * shf;
    shv = readTextFile(pVSFileName);
    
    if (shv == NULL) {
        fprintf(stderr, "Error load shader file!\n");
        exit(1);
    };

    shf = readTextFile(pFSFileName);

    if (shf == NULL) {
        fprintf(stderr, "Error load shader file!\n");
        exit(1);
    };

    
    AddShader(ShaderProgram, shv ,GL_VERTEX_SHADER);

    AddShader(ShaderProgram, shf, GL_FRAGMENT_SHADER);

    GLint Success = 0;
    GLchar ErrorLog[1024] = { 0 };

    glLinkProgram(ShaderProgram);



    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0) {
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
        exit(1);
	}
    
    glValidateProgram(ShaderProgram);
    glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
    if (!Success) {
        glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
        exit(1);
    }

    return ShaderProgram;

}

// Função para salvar dados da textura em um arquivo BMP
void salvarTexturaComoBMP(const char* nomeArquivo, int largura, int altura, const unsigned char* data) {
    // O cabeçalho BMP tem 54 bytes
    int tamanhoCabecalho = 54;

    // Cabeçalho BMP
    unsigned char cabecalhoBMP[tamanhoCabecalho] = {
        0x42, 0x4D,                     // "BM" - Identificador BMP
        0, 0, 0, 0,                     // Tamanho do arquivo em bytes (será preenchido mais tarde)
        0, 0, 0, 0,                     // Reservado
        54, 0, 0, 0,                    // Tamanho do cabeçalho
        40, 0, 0, 0,                    // Tamanho do cabeçalho de informações
        static_cast<unsigned char>(largura), static_cast<unsigned char>(largura >> 8), static_cast<unsigned char>(largura >> 16), static_cast<unsigned char>(largura >> 24),  // largura
        static_cast<unsigned char>(altura), static_cast<unsigned char>(altura >> 8), static_cast<unsigned char>(altura >> 16), static_cast<unsigned char>(altura >> 24),  // altura
        1, 0,                            // Planos de cores (1)
        24, 0,                           // Bits por pixel (24 para cores RGB)
        0, 0, 0, 0,                     // Compressão (0 para sem compressão)
        0, 0, 0, 0,                     // Tamanho da imagem após compressão (0 para sem compressão)
        0, 0, 0, 0,                     // Resolução horizontal em pixels por metro (0 para valor padrão)
        0, 0, 0, 0,                     // Resolução vertical em pixels por metro (0 para valor padrão)
        0, 0, 0, 0,                     // Cores na paleta (0 para usar todas as cores disponíveis)
        0, 0, 0, 0                      // Cores importantes (0 para todas as cores importantes)
    };

    // Preencher o tamanho do arquivo no cabeçalho
    int tamanhoArquivo = tamanhoCabecalho + largura * altura * 3;  // 3 bytes por pixel (sem alfa)
    cabecalhoBMP[2] = static_cast<unsigned char>(tamanhoArquivo);
    cabecalhoBMP[3] = static_cast<unsigned char>(tamanhoArquivo >> 8);
    cabecalhoBMP[4] = static_cast<unsigned char>(tamanhoArquivo >> 16);
    cabecalhoBMP[5] = static_cast<unsigned char>(tamanhoArquivo >> 24);

    // Escrever cabeçalho BMP e dados da textura no arquivo
    std::ofstream arquivo(nomeArquivo, std::ios::binary);
    arquivo.write(reinterpret_cast<char*>(cabecalhoBMP), tamanhoCabecalho);
    arquivo.write(reinterpret_cast<const char*>(data), largura * altura * 3);  // 3 bytes por pixel (sem alfa)
    arquivo.close();
}

void SalvarTexura2Image(const char* nomeArquivo,int W,int H,int C,bool normalizar = true) {
    // Ler os dados da textura de volta para a CPU
    GLint activeTexture;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &activeTexture);

    GLint boundTexture;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &boundTexture);

    // Impressão das informações
    std::cout << "Unidade de textura ativa: " << activeTexture << std::endl;
    std::cout << "Textura vinculada à unidade ativa: " << boundTexture << std::endl;

    float*  depthData = new float[W* H*C]; // RGBA format
    if(C == 1)
        glGetTexImage(GL_TEXTURE_2D, 0,GL_DEPTH_COMPONENT, GL_FLOAT, depthData);
    else if(C==3)
        glGetTexImage(GL_TEXTURE_2D, 0,GL_RGB, GL_FLOAT, depthData);
    else{
        cout << "Numero C deve ser 1 ou 3" << endl;
        return;
    }
    GLenum error;
    error = glGetError();
    if (error != GL_NO_ERROR) {
        cout << "OpenGL Error: " << error << std::endl;
        if(error == GL_INVALID_ENUM)
          cout << "GL_INVALID_ENUM" << endl;
        if(error == GL_INVALID_OPERATION)
          cout << "GL_INVALID_OPERATION" << endl;
        return;
    }
    float minDepth = 1.0f; // Valor inicial alto
    float maxDepth = 0.0f; // Valor inicial baixo

    if(normalizar){

        for (int i = 0; i < W * H*C; ++i) {
            minDepth = std::min(minDepth, depthData[i]);
            maxDepth = std::max(maxDepth, depthData[i]);
        }
        cout << minDepth << " " << maxDepth << endl;
    }else{
        minDepth = 0.0;
        maxDepth = 1.0;
    }
    // Criar um buffer de imagem em tons de cinza
    unsigned char* imageData = new unsigned char[W * H*3];
    
    for (int i = 0; i < W * H; ++i) {
        // Armazenar no buffer de imagem
        if (C == 3){
           float normalizedDepth = (depthData[i*3 + 2] - minDepth) / (maxDepth - minDepth);
           unsigned char grayValue = static_cast<unsigned char>(normalizedDepth * 255);
           imageData[3*i] = grayValue;
           normalizedDepth = (depthData[i*3 + 1] - minDepth) / (maxDepth - minDepth);
           grayValue = static_cast<unsigned char>(normalizedDepth * 255);
           imageData[3*i + 1] = grayValue;
           normalizedDepth = (depthData[i*3] - minDepth) / (maxDepth - minDepth);
           grayValue = static_cast<unsigned char>(normalizedDepth * 255);
           imageData[3*i + 2] = grayValue;
        }
        if (C == 1){
           float normalizedDepth = (depthData[i] - minDepth) / (maxDepth - minDepth);
           unsigned char grayValue = static_cast<unsigned char>(normalizedDepth * 255);
           imageData[3*i] = grayValue;
           imageData[3*i + 1] = grayValue;
           imageData[3*i + 2] = grayValue; 
        }
    }
    salvarTexturaComoBMP(nomeArquivo, W, H, imageData);
   
}


#endif