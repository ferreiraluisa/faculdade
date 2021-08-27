#include "split.h"


//construtores
Split::Split(){}

Split::Split(string ticker,string data, string split):
    _ticker(ticker) , _data(data) , _split(split) {}

//destrutor 
Split::~Split(){}


//getters
string Split::getTicker(){
    return this->_ticker;
}
string Split::getData(){
    return this->_data;
}
string Split::getSplit(){
    return this->_split;
}