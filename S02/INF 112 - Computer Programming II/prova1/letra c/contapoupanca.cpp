#include "contapoupanca.h"

ContaPoupanca::ContaPoupanca(std::string nome, std::string cpf, double saldo):
    Conta(nome,cpf,saldo) {}

ContaPoupanca::~ContaPoupanca(){}

void ContaPoupanca::muda_rendimento(double rendimento){
    _rendimento = rendimento;
}

double ContaPoupanca::get_saldo(){
    return (Conta::get_saldo())+((_rendimento/100)*Conta::get_saldo()); //rendimento esta em porcentagem, ex.: _rendimento = 3(%)
}

