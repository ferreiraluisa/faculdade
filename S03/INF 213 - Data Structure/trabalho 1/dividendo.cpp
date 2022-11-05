#include "dividendo.h"
//construtores
Dividendo::Dividendo(){}

Dividendo::Dividendo(std::string ticker,string data, int valorDividendo):
    _ticker(ticker) , _data(data) , _valorDividendo(valorDividendo) {}
//destrutor
Dividendo::~Dividendo(){}
//getters
std::string Dividendo::getTicker(){
    return this->_ticker;
}

string Dividendo::getData(){
    return this->_data;
}

int Dividendo::getValorDividendo(){
    return this->_valorDividendo;
}