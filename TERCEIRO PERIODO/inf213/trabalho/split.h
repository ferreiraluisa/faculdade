#ifndef SPLIT_H
#define SPLIT_H
#include <string>
using namespace std;
class Split{
    private:
        string _ticker;
        string _data;
        string _split;
    public:
        //construtores
        Split();
        Split(string ticker,string data, string split);
        //destrutor
        ~Split();
        //getters
        string getSplit();
        string getTicker();
        string getData();


};

#endif