#ifndef ACAO_H
#define ACAO_H
#include <string>
#include "classeBase.h"
using namespace std;

class Acao {
    private:
        string _ticker;
        string _data;
        Preco *precos;
        Dividendo *dividendos;
        Split *splits;
        int sizePrecos;
        int sizeDividendos;
        int sizeSplits;
        int dia;
        int mes;
        int ano;

    public:
        int _quantidade; 
        int _custoMedio;
        Acao();
        Acao(string ticker,int quantidade, int n);
        ~Acao();
        void armazenandoDados(Preco *preco, int n,Dividendo *dividendo, int o,Split *split, int p);
        void imprime();
        int dataToInt(string data);
        int dataMinima(string data);
        string ultimoDiaUtil(string data);
        string getTicker();
        Preco *getPrecoAcao();
        Dividendo *getDividendoAcao();
        Split *getSplitAcao();

};

#endif