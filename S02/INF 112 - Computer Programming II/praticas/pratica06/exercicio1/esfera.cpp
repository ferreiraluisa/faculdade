#include "esfera.h"

Esfera::Esfera(std::string nome, std::string cor, double raio):
    _nome(nome), _cor(cor), _raio(raio) {}

Esfera::~Esfera() {}


std::string Esfera::get_cor(){
    return this->_cor;
}

std::string Esfera::get_nome(){
    return this->_nome;
}

double Esfera::get_volume(){
    return (this->_raio * this->_raio * this->_raio * 4 * 3.14159)/3;
}

