#pragma once
#ifndef PRECO_H
#define PRECO_H
#include <string>

using namespace std;

class Preco{
    private:
        string _ticker;
        string _data;
        int _preco;
    public:
        //construtores
        Preco();
        Preco(string ticker,string data, int preco);
        //destrutores
        ~Preco();
        //getters
        string getData();
        string getTicker();
        int getPreco();
};

#endif