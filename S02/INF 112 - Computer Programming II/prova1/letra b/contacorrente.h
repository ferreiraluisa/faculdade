#ifndef INF112_CONTACORRENTE_H
#define INF112_CONTACORRENTE_H
#include "conta.h"
class ContaCorrente : public Conta{
    public:
        ContaCorrente(std::string nome, std::string cpf, double saldo); //construtor
        ~ContaCorrente(); //destrutor
};

#endif