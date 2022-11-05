#ifndef CARTEIRA_INVESTIDOR_H
#define CARTEIRA_INVESTIDOR_H
#include <string>
#include "classeBase.h"
#include "Acao.h"
#include "operacoes.h"
using namespace std;

class CarteiraInvestidor : public classeBase{
    private:
        int patrimonio;
        int _custoCompra;
        int quantidade;
        int ticker;
        Acao *acoes;
    public:
        CarteiraInvestidor();
        CarteiraInvestidor(int n);
        ~CarteiraInvestidor();
        int buscaBinAcao(string chave);
        int buscaBinData(int chave, int pos);
        void compraVenda();
        bool acaoRepetida(string ticker);
        int dataToInt(string data);
};

#endif