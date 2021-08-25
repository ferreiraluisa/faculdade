#ifndef SPLIT_H
#define SPLIT_H
#include <string>
class Split{
    private:
        std::string _ticker;
        int _data;
        std::string _split;
    public:
        //construtores
        Split();
        Split(std::string ticker,int data, std::string split);
        //destrutor
        ~Split();
        //getters
        std::string getTicker();
        int getData();


};

#endif