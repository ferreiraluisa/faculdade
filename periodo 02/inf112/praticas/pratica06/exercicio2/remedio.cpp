#include "remedio.h"

Remedio::Remedio(int codigo, std::string descricao, double preco, double desconto, double lucro):
    _codigo(codigo) , _descricao(descricao) , _preco(preco), _desconto(desconto), _lucro(lucro) {}

Remedio::~Remedio() {}

int Remedio::get_codigo(){
    return this->_codigo;
}

double Remedio::get_desconto(){
    return this->_desconto;
}

std::string Remedio::get_descricao(){
    return this->_descricao;
}

double Remedio::get_preco_de_compra(){
    return this->_preco;
}

double Remedio::get_lucro(){
    return this->_lucro;
} 

double Remedio::gerarprecodevenda() {
    return (this->_preco + (this->_lucro * this->_preco)) - this->_desconto;
}

