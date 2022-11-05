#pragma once
#ifndef CARTEIRA_INVESTIDOR_H
#define CARTEIRA_INVESTIDOR_H
#pragma once
#include "Acao.h"
#include "operacoes.h"
#include <string>
#include <iostream>

using namespace std;

class CarteiraInvestidor{
    private:
        int patrimonio;
        int custoCompra;
        int sizeAcoes;
    public:
        Acao *acoes;
        CarteiraInvestidor();
        CarteiraInvestidor(int const &n);
        ~CarteiraInvestidor();
        int buscaBinTicker(string chave, int n);
        void armazenandoDadosAcoes(Operacoes *op, int m, Preco *preco, int n, Dividendo *dividendos,int o, Split splits, int p);
        void imprime();

};

#endif