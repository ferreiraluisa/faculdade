#include "artigoshigiene.h"

ArtigosHigiene::ArtigosHigiene(int codigo, std::string descricao, double preco):
    _codigo(codigo) , _descricao(descricao) , _preco(preco), _lucro(0.3) {}

ArtigosHigiene::~ArtigosHigiene() {}

int ArtigosHigiene::get_codigo(){
    return this->_codigo;
}

std::string ArtigosHigiene::get_descricao(){
    return this->_descricao;
}

double ArtigosHigiene::get_preco_de_compra(){
    return this->_preco;
}

double ArtigosHigiene::get_lucro(){
    return this->_lucro;
} 

double ArtigosHigiene::gerarprecodevenda() {
    return this->_preco + (this->_lucro * this->_preco);
}

