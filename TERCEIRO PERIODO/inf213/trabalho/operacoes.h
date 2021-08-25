#ifndef OPERACOES_H
#define OPERACOES_H
#include <string>

class Operacoes{
    public:
        std::string _ticker;
        int _data;
        std::string _operacaoPrincipal; //primeira linha do arquivo, aquele char
        std::string _operacaoSecundaria;// as operacoes
    public:
        //construtores
        Operacoes();
        Operacoes(std::string ticker,int data, std::string operacaosecundaria,std::string operacaoprincipal);
        //destrutor 
        ~Operacoes();
        //getters
        std::string getTicker();
        int getData();
};

#endif