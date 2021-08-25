#ifndef DIVIDENDOS_H
#define DIVIDENDOS_H
#include <string>

class Dividendo{
    private:
        std::string _ticker;
        int _data;
        int _valorDividendo;
    public:
        //construtores
        Dividendo();
        Dividendo(std::string ticker,int data, int dividendo);
        //destrutor
        ~Dividendo();
        //getters
        std::string getTicker();
        int getData();
};
#endif