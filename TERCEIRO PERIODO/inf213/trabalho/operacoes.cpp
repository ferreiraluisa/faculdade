#include "operacoes.h"

//construtores
Operacoes::Operacoes(){}

Operacoes::Operacoes(string ticker,string data,char operacaoPrincipal,char operacaoSecundaria, int quantidade):
    _ticker(ticker) , _data(data) , _operacaoPrincipal(operacaoPrincipal), _operacaoSecundaria(operacaoSecundaria), _quantidade(quantidade) {}

//destrutor
Operacoes::~Operacoes(){}

//getters
char Operacoes::getOperacaoPrincipal(){
    return this->_operacaoPrincipal;
}
string Operacoes::getTicker(){
    return this->_ticker;
}
string Operacoes::getData(){
    return this->_data;
}
char Operacoes::getOperacaoSecundaria(){
    return this->_operacaoSecundaria;
}
int Operacoes::getQuantidade(){
    return this->_quantidade;
}