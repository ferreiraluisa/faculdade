#include <iostream>
using namespace std;

int main() {
    int andar,capacidade;
    int saldo,entrada,saida,cont;
    int i;

    cont = 0;
    i = 0;

    cin>>andar>>capacidade;

    while(i<=andar){
        cin>>saida>>entrada;
        saldo += (entrada-saida);
        i++;
        if(saldo>capacidade)
            cont++;
    }
    if(cont>=1)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;
    
    return 0;
}