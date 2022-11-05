#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int andar,capacidade;
    int entrada,saida,cont,saldo;
    int i;

    cont = 0;
    saldo = 0;

    cin>>andar>>capacidade;

    for(i=0;i<andar;i++){
        cin>>saida>>entrada;
        saldo+=(entrada-saida);
        if(saldo>capacidade){
            cont++;
    }}
    if(cont>=1)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;

    return 0;

    
}