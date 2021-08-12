#include <iostream>
using namespace std;

int main () {
    int produto;
    char mouc; //moeda ou cedula
    double valor, soma, troco, preco;
    valor = 1;
    soma = 0;

    cin>>produto;

    while(valor != 0){
        cin>>mouc>>valor;
        if(mouc=='M'||mouc=='m') //se for moeda, dividir o valor por 100 ja que é centavos de real
            valor= valor/100;
        soma +=valor; //soma do valor total colocado na maquina
    }
    if(produto==1)
        preco = 4.3; // batata shuffles R$4.30
    else if(produto==2)
        preco = 2.7;  // suco c mais R$2.70
    else if(produto==3)
        preco = 1.43;  // guarana qwerty R$1.43
    if(produto==1||produto==2||produto==3){
        if(soma>=preco){ //se tiver troco!
            troco=soma-preco;
            while(troco>0){
                if(troco>=100){
                    cout<<"C 100"<<endl;
                    troco -= 100; // diminuir 100 do troco toda vez que for contabilizado 1 cedula de 100 
                }
                else if(troco>=50){
                    cout<<"C 50"<<endl;
                    troco -= 50; // diminuir 50 do troco toda vez que for contabilizado 1 cedula de 50 
                }
                else if(troco>=20){
                    cout<<"C 20"<<endl;
                    troco -=20; // diminuir 20 do troco toda vez que for contabilizado 1 cedula de 20 
                }
                else if(troco>=10){
                    cout<<"C 10"<<endl;
                    troco -= 10; // diminuir 10 do troco toda vez que for contabilizado 1 cedula de 10
                }
                else if(troco>=5){
                    cout<<"C 5"<<endl;
                    troco -= 5; // diminuir 5 do troco toda vez que for contabilizado 1 cedula de 5 
                }
                else if(troco>=2){
                    cout<<"C 2"<<endl;
                    troco -=2; // diminuir 2 do troco toda vez que for contabilizado 1 cedula de 2 
                }
                else if(troco>=1){
                    cout<<"M 100"<<endl;
                    troco -=1; // diminuir 1 do troco toda vez que for contabilizado 1 moeda de 1 real 
                }
                else if(troco>0.49){
                    cout<<"M 50"<<endl;
                    troco-=0.5; // diminuir 0.5 do troco toda vez que for contabilizado 1 moeda de 50 centavos 
                }
                else if(troco>0.24){
                    cout<<"M 25"<<endl;
                    troco -= 0.25; // diminuir 0.25 do troco toda vez que for contabilizado 1 moeda de 25 centavos  
                }
                else if(troco>0.09){
                    cout<<"M 10"<<endl;
                    troco -= 0.1; // diminuir 0.1 do troco toda vez que for contabilizado 1 moeda de 10 centavos 
                }
                else if(troco>0.04){
                    cout<<"M 5"<<endl;
                    troco -=0.05; // diminuir 0.05 do troco toda vez que for contabilizado 1 moeda de 5 centavos 
                }
                else if(troco>=0.01){
                    cout<<"M 1"<<endl;
                    troco -=0.01; // diminuir 0.01 do troco toda vez que for contabilizado 1 moeda de 1 centavo  
                }

            }
        }
        else{  //se nao tiver troco
            cout<<"Saldo insuficiente."<<endl;
        }
    }
    else  //se nao tiver produto correspondente ao numero armazenado a variavel produto
        cout<<"Produto inexistente."<<endl;
    
    return 0;   

}