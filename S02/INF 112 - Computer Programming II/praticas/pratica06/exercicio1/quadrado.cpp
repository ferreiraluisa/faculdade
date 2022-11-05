#include "quadrado.h"

Quadrado::Quadrado(std::string nome, std::string cor, double lado):
    _nome(nome), _cor(cor), _lado(lado) {}

Quadrado::~Quadrado() {}


std::string Quadrado::get_cor(){
    return this->_cor;
}

std::string Quadrado::get_nome(){
    return this->_nome;
}

double Quadrado::get_area(){
    return this->_lado * this->_lado;
}

double Quadrado::get_perimetro(){
    return this->_lado * 4; 
}

