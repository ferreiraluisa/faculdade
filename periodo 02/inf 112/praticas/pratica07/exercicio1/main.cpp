#include <iostream>
#include "excecaosoma.h"

int main(){
    int n;

    std::cin>>n;

    Excecao obj(n);

    obj.le_numeros();

    std::cout<<"Soma maxima: "<<obj._soma<<std::endl;
    std::cout<<"Media: "<<obj._media<<std::endl;
    std::cout<<"Vezes: "<<obj._vezes<<std::endl;

    

    return 0;


}