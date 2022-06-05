#include "preco.h"

//construtores
Preco::Preco(){}

Preco::Preco(std::string ticker, string data, int preco) : _ticker(ticker), _data(data), _preco(preco) {}

//destrutores
Preco::~Preco() {}

//getters
std::string Preco::getTicker(){
    return this->_ticker;
}

string Preco::getData(){
    return this->_data;
}

int Preco::getPreco(){
    return this->_preco;
}