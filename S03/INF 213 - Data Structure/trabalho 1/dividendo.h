#pragma once
#ifndef DIVIDENDOS_H
#define DIVIDENDOS_H
#include <string>
using namespace std;

class Dividendo{
    private:
        string _ticker;
        string  _data;
        int _valorDividendo;
    public:
        //construtores
        Dividendo();
        Dividendo(string ticker,string data, int dividendo);
        //destrutor
        ~Dividendo();
        //getters
        int getValorDividendo();
        string getTicker();
        string getData();
};
#endif