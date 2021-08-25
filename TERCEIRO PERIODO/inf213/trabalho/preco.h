#ifndef PRECO_H
#define PRECO_H
#include <string>

class Preco{
    private:
        std::string _ticker;
        int _data;
        int _preco;
    public:
        //construtores
        Preco();
        Preco(std::string ticker,int data, int preco);
        //destrutores
        ~Preco();
        //getters
        int getData();
        std::string getTicker();
        int getPreco();
};

#endif