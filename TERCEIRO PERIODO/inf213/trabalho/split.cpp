#include "split.h"


//construtores
Split::Split(){}

Split::Split(std::string ticker,int data, std::string split):
    _ticker(ticker) , _data(data) , _split(split) {}

//destrutor 
Split::~Split(){}


//getters
std::string Split::getTicker(){
    return this->_ticker;
}
int Split::getData(){
    return this->_data;
}