#include "circulo.h"

static double pi = 3.14159;

Circulo::Circulo(std::string nome, std::string cor, double raio):
    _nome(nome) , _cor(cor) , _raio(raio) {}

Circulo::~Circulo() {}

std::string Circulo::get_cor(){
    return this->_cor;
}

std::string Circulo::get_nome(){
    return this->_nome;
}

double Circulo::get_area(){
    return pi* this->_raio * this->_raio;
} 

double Circulo::get_perimetro(){ // 2p = circunferencia 
    return 2 * pi * this->_raio;
}

