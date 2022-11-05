#include "alunos.h"
#include <iostream>
#include <bitset>

Alunos::Alunos(int matricula, std::string nome, double nota1, double nota2){
    _matricula = matricula;
    _nome = nome;
    _nota1 = nota1;
    _nota2 = nota2;
    _media = (nota1+nota2)/2;
}

Alunos::~Alunos(){}

bool Alunos::maior_media(Alunos comparacao){
    if(this->_media > comparacao._media){
        return true;
    }
    else{
        return false;
    }
}

void Alunos::matricula_binario_invertido(){
    std::bitset<4> bs(this->_matricula);
    std::cout<< bs.flip();
}