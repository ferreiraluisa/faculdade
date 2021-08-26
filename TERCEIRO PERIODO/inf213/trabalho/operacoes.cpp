#include "operacoes.h"

//construtores
Operacoes::Operacoes(){}

Operacoes::Operacoes(std::string ticker,int data,char operacaoPrincipal,char operacaoSecundaria, int quantidade):
    _ticker(ticker) , _data(data) , _operacaoPrincipal(operacaoPrincipal), _operacaoSecundaria(operacaoSecundaria), _quantidade(quantidade) {}

//destrutor
Operacoes::~Operacoes(){}

//getters
char Operacoes::getOperacaoPrincipal(){
    return this->_operacaoPrincipal;
}
std::string Operacoes::getTicker(){
    return this->_ticker;
}
int Operacoes::getData(){
    return this->_data;
}