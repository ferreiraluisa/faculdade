#ifndef INF112_CONTAPOUPANCA_H
#define INF112_CONTAPOUOANCA_H
#include "conta.h"

class ContaPoupanca : public Conta{
    public:
        static double _rendimento;
        ContaPoupanca(std::string nome, std::string cpf, double saldo);
        ~ContaPoupanca();
        void muda_rendimento(double rendimento);
        virtual double get_saldo() override;
};
#endif