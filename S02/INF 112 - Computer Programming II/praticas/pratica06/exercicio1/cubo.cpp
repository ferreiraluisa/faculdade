#include "cubo.h"

Cubo::Cubo(std::string nome, std::string cor, double lado):
    _nome(nome), _cor(cor), _lado(lado) {}

Cubo::~Cubo() {}


std::string Cubo::get_cor(){
    return this->_cor;
}

std::string Cubo::get_nome(){
    return this->_nome;
}

double Cubo::get_volume(){
    return this->_lado * this->_lado * this->_lado ;
}

