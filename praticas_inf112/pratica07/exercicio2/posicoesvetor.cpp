#include <iostream>
#include <limits>
#include "posicoesvetor.h"

PosicoesVetor::PosicoesVetor(int n){
    _n = n;
}
PosicoesVetor::~PosicoesVetor(){}


int PosicoesVetor::excecao_nao_numero(int n){
    if(std::cin.fail()){
        throw std::invalid_argument("ERRO! Nao foi digitado um numero inteiro.");
    }
    else{
        return n;
    }
}
        
int PosicoesVetor::excecao_inexistente(int n){
    if(n>=_n){
        throw "ERRO! Posicao inexistente";
    }
    else{
        return n;
    }
}
        
void PosicoesVetor::le_posicoes(){
    for(int i=0;i<_n;i++){
        while(true){
            std::cout<<"Digite o "<<i+1<<" elemento: ";
            std::cin>>_vetor[i];
            try{
                excecao_nao_numero(_vetor[i]);
                break;
            }catch(std::invalid_argument &erro){
                std::cerr<<erro.what()<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}
        