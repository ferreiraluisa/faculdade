#include "dividendo.h"
//construtores
Dividendo::Dividendo(){}

Dividendo::Dividendo(std::string ticker,int data, int valorDividendo):
    _ticker(ticker) , _data(data) , _valorDividendo(valorDividendo) {}
//destrutor
Dividendo::~Dividendo(){}
//getters
std::string Dividendo::getTicker(){
    return this->_ticker;
}

int Dividendo::getData(){
    return this->_data;
}