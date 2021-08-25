#include "operacoes.h"

//construtores
Operacoes::Operacoes(){}

Operacoes::Operacoes(std::string ticker,int data, std::string operacaosecundaria,std::string operacaoPrincipal):
    _ticker(ticker) , _data(data) , _operacaoPrincipal(operacaoPrincipal), _operacaoSecundaria(operacaosecundaria) {}

//destrutor
Operacoes::~Operacoes(){}

//getters
std::string Operacoes::getTicker(){
    return this->_ticker;
}
int Operacoes::getData(){
    return this->_data;
}