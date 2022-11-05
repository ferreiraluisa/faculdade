#include <iostream>
using namespace std;

int main () {
    int produto;
    char mouc; //moeda ou cedula
    int valor, soma, troco, preco;
    valor = 1;
    soma = 0;

    cin>>produto;

    do{
        cin>>mouc>>valor;
        if(mouc=='C'||mouc=='c') //se for cedula, multiplicar o valor por 100 ja que estamos usando centavos de real
            valor= valor*100;
        soma +=valor; //soma do valor total colocado na maquina
    }while(valor != 0);
    
    if(produto==1)
        preco = 430; // batata shuffles R$4.30
    else if(produto==2)
        preco = 270;  // suco c mais R$2.70
    else if(produto==3)
        preco = 143;  // guarana qwerty R$1.43
    if(produto==1||produto==2||produto==3){
        if(soma>=preco){ //se tiver troco!
            troco=soma-preco;
            while(troco>0){
                if(troco>=10000){
                    cout<<"C 100"<<endl;
                    troco -= 10000; // diminuir 10000(100 reais) do troco toda vez que for contabilizado 1 cedula de 100 
                }
                else if(troco>=5000){
                    cout<<"C 50"<<endl;
                    troco -= 5000; // diminuir 5000(50 reais) do troco toda vez que for contabilizado 1 cedula de 50 
                }
                else if(troco>=2000){
                    cout<<"C 20"<<endl;
                    troco -=2000; // diminuir 2000(20 reais) do troco toda vez que for contabilizado 1 cedula de 20 
                }
                else if(troco>=1000){
                    cout<<"C 10"<<endl;
                    troco -= 1000; // diminuir 1000(10 reais) do troco toda vez que for contabilizado 1 cedula de 10
                }
                else if(troco>=500){
                    cout<<"C 5"<<endl;
                    troco -= 500; // diminuir 500(5 reais) do troco toda vez que for contabilizado 1 cedula de 5 
                }
                else if(troco>=200){
                    cout<<"C 2"<<endl;
                    troco -=200; // diminuir 200(2 reais) do troco toda vez que for contabilizado 1 cedula de 2 
                }
                else if(troco>=100){
                    cout<<"M 100"<<endl;
                    troco -=100; // diminuir 100 do troco toda vez que for contabilizado 1 moeda de 1 real 
                }
                else if(troco>=50){
                    cout<<"M 50"<<endl;
                    troco-=50; // diminuir 50 do troco toda vez que for contabilizado 1 moeda de 50 centavos 
                }
                else if(troco>=25){
                    cout<<"M 25"<<endl;
                    troco -= 25; // diminuir 25 do troco toda vez que for contabilizado 1 moeda de 25 centavos  
                }
                else if(troco>=10){
                    cout<<"M 10"<<endl;
                    troco -= 10; // diminuir 10 do troco toda vez que for contabilizado 1 moeda de 10 centavos 
                }
                else if(troco>=5){
                    cout<<"M 5"<<endl;
                    troco -=5; // diminuir 5 do troco toda vez que for contabilizado 1 moeda de 5 centavos
                }
                else if(troco>=1){
                    cout<<"M 1"<<endl;
                    troco -=1; // diminuir 1 do troco toda vez que for contabilizado 1 moeda de 1 centavo  
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