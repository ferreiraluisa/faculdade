#include "conta.h"

Conta::Conta(std::string nome, std::string cpf, double saldoatual): //Construtor com Initializer List
    _nome(nome) , _cpf(cpf) , _saldoatual(saldoatual) {}

Conta::~Conta(){}

void Conta::set_saldo(double saldo){
    this->_saldoatual = saldo;
}

double Conta::get_saldo(){
    return this->_saldoatual;
}
