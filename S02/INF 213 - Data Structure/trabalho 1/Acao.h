#ifndef ACAO_H
#define ACAO_H
#include <string>
#include <sstream>
#pragma
#include "preco.h"
#include "operacoes.h"
#include "dividendo.h"
#include "split.h"
using namespace std;

class Acao {
    private:
        string _ticker;
        int sizeCotacoes;
        int sizeDividendos;
        int sizeSplits;
    public:
        Preco *cotacoes;
        Dividendo * dividendos;
        Split *splits;
        int _custoMedio;
        int _quantidade;
        int lucro;
        Acao();
        Acao(string ticker, int quantidade);
        ~Acao();
        int dataToInt(string data);
        int buscaBinData(string data);
        void armazenandoDados(Preco *preco, int n, Dividendo *dividendo, int o, Split *split, int p);
        void armazenandoPreco(Preco *p, int n);
        void armazenandoDividendo(Dividendo *p, int n);
        void armazenandoSplit(Split *p, int n);
        int dataMinima(string data);
        string ultimoDiaUtil(string data);
        void imprimeTeste();
        string getTicker();
        void setTicker(string ticker);

};

#endif