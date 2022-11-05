#include <iostream>
using namespace std;

int main () {
    int preco;
    int moeda,soma,troco;
    moeda = 1;
    soma=0;

    cin>>preco;
    
    while(moeda!=0){
        cin>>moeda;
        soma += moeda;
    }
    if(soma>=preco){
        troco = soma-preco;
        cout<<"Troco de "<<troco<<" centavos."<<endl;
    }
    else
        cout<<"Saldo insuficiente."<<endl;


    return 0;

}
