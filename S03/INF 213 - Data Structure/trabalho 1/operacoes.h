#ifndef OPERACOES_H
#define OPERACOES_H
#include <string>
using namespace std;

class Operacoes{
    private:
        string _ticker;
        string _data;
        char _operacaoPrincipal; //primeira linha do arquivo, aquele char
        char _operacaoSecundaria;// as operacoes em si
        int _quantidade;
    public:
        //construtores
        Operacoes();
        Operacoes(string ticker,string data,char operacaoPrincipal,char operacaoSecundaria,int quantidade);
        //destrutor 
        ~Operacoes();
        //getters
        char getOperacaoPrincipal();
        string getTicker();
        string getData();
        char getOperacaoSecundaria();
        int getQuantidade();
};

#endif