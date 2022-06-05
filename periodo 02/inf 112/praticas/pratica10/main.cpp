#include <iostream>
#include <vector>
#include "alunos.h"

int main(){
    int matricula;
    double nota1, nota2;
    std::string nome;
    std::vector<Alunos> alunos;

    while(std::cin>>matricula && matricula!=-1){
        std::cin>>nome;
        std::cin>>nota1;
        std::cin>>nota2;

        alunos.push_back(Alunos(matricula, nome, nota1, nota2));
    }

    int vezes = alunos.size();
    
    if(alunos.size()==2){
        if(alunos[0]._media<alunos[1]._media){
            Alunos aux = alunos[0];
            alunos[0] = alunos[1];
            alunos[1] = aux;
        }
    }
    else if(alunos.size()>2){
        for(int i;i<vezes-1;i++){ //BubbleSort
            for(int j;j<vezes-1-i;j++){
                if(alunos[j].maior_media(alunos[j+1])){
                    Alunos aux = alunos[j];
                    alunos[j+1] = alunos[j];
                    alunos[j] = aux;
                }
            }
        }
    }

    for(int i=0;i<vezes;i++){
        alunos[i].matricula_binario_invertido();
        std::cout<<" - "<<alunos[i]._nome<<" - "<<alunos[i]._media<<std::endl;
    }

}