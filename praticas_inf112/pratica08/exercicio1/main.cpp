#include <iostream>
#include "keywords.h"

int main(){

    std::string nome;

    std::cout<<"Digite o nome do arquivo: "; //texto.txt
    std::cin>>nome;

    KeyWords *obj = new KeyWords(nome); 

    obj->find_keywords();


    delete obj;
    return 0;
}