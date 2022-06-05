#include "triangulo.h"
#include <cmath>

Triangulo::Triangulo(std::string nome, std::string cor, double ladoa, double ladob, double ladoc):
    _nome(nome) , _cor(cor) , _lado_a(ladoa) , _lado_b(ladob) , _lado_c(ladoc) {}

Triangulo::~Triangulo() {}

std::string Triangulo::get_cor(){
    return this->_cor;
}

std::string Triangulo::get_nome(){
    return this->_nome;
}

double Triangulo::get_area(){
    double semiperimetro = (this->_lado_a + this->_lado_b + this->_lado_c)/2; //Formula de Heron 
    double area = sqrt(semiperimetro * (semiperimetro - this->_lado_a) *(semiperimetro - this->_lado_b) *(semiperimetro - this->_lado_c));
    return area;
} 

double Triangulo::get_perimetro(){ 
    return this->_lado_a + this->_lado_b + this->_lado_c;
}

