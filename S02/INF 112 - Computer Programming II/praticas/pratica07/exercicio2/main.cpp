#include <iostream>
#include "posicoesvetor.h"

int main(){
    int n;

    std::cout<<"Qual tamanho do vetor? ";
    std::cin>>n;


    PosicoesVetor obj(n);

    obj.le_posicoes();

    std::cout<<"V["<<n<<"] = {";

    for(int i=0;i<n;i++){
        if(i==n-1)
            std::cout<<obj._vetor[i];
        else
            std::cout<<obj._vetor[i]<<" , ";
    }

    std::cout<<"}"<<std::endl;

    std::cout<<"Digite a posicao que deseja observar: ";
    std::cin>>n;

    try{
        obj.excecao_inexistente(n-1); //botei n-1 pensando que o usario leva em consideracao que as posicoes vao de 1 - 5 e nao de 0 - 4
        std::cout<<obj._vetor[n-1]<<std::endl;
    } catch(const char *e){
        std::cerr<<e<<std::endl;
    }
    

    return 0;
}