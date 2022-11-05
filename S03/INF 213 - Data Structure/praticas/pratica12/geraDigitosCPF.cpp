#include <iostream>
#include <string>
#include "MyHashMap.h"
using namespace std;

int main(){
    int numVezes;
    string cpf;
    string primeiroDigito;
    string segundoDigito;
    cin>>numVezes;
    for(int i=0;i<numVezes;i++){
        cin>>cpf;
        int n = 10;
        int soma = 0;
        for(int i=0;i<9;i++){
            char aux = cpf[i];
            soma += n * stoi(&aux);
            n--;
        }
        (soma*10)%11 >= 10 ? primeiroDigito = "0" : primeiroDigito = to_string((soma*10)%11);
        cpf = cpf + primeiroDigito;
        n=11;
        soma = 0;
        for(int i=0;i<10;i++){
            char aux = cpf[i];
            soma += n * stoi(&aux);
            n--;
        }
        segundoDigito = to_string((soma*10)%11);
        cout<<primeiroDigito<<segundoDigito<<endl;

    }
}