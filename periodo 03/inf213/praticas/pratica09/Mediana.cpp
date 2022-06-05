#include <iostream>
#include "Mediana.h"

void Mediana::insere(int elem){
    if(menores.empty() && maiores.empty()){
        menores.push(elem);
    }
    else{
        if(elem > menores.top()){
            maiores.push(-elem);
        }
        else{
            menores.push(elem);
        }
    }
    checkSize();
}

int Mediana::getMediana(){
    int total = maiores.size() + menores.size();
    if(total%2==0){
        return (menores.top() - maiores.top())/2; //- maior pq ta negativo pra ficar decrescente a fila de prioridade.
    }
    else{
        if(menores.size() > maiores.size()){
            return menores.top();
        }
        else{
            return -maiores.top();
        }
    }
}

void Mediana::checkSize(){
    // if(menores.size() - maiores.size() == 2){
        
    // }
    if(menores.size() - maiores.size() == 2){ //passar da fila menor pra fila maior
        maiores.push(-(menores.top()));
        menores.pop();
    }
    if(maiores.size() - menores.size() == 2){ //passar da fila maior pra fila menor
        int aux = -maiores.top();
        maiores.pop();
        menores.push(aux);
    }
}