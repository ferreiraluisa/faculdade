#ifndef OPERACOES_H
#define OPERACOES_H
#include <string>

class Operacoes{
    private:
        std::string _ticker;
        int _data;
        char _operacaoPrincipal; //primeira linha do arquivo, aquele char
        char _operacaoSecundaria;// as operacoes
        int _quantidade;
    public:
        //construtores
        Operacoes();
        Operacoes(std::string ticker,int data,char operacaoPrincipal,char operacaoSecundaria,int quantidade);
        //destrutor 
        ~Operacoes();
        //getters
        char getOperacaoPrincipal();
        std::string getTicker();
        int getData();
};

#endif