#include <iostream>
using namespace std;

int main(){
    int produto;
    char mouc; //moeda ou cedula
    double valor, soma, troco, preco;
    int trocoint,centavosint;
    double centavos;
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
            trocoint = int(troco); //troco inteiro, sem os centavos, para contabilizar as cedulas do troco
            centavos = (troco-trocoint)*100; //multiplica por 100 so pra nao ficar como numero flutuante(opcional)
            while(trocoint>=100){     
                    cout<<"C 100"<<endl;
                    trocoint -= 100;     // diminuir 100 do troco toda vez que for contabilizado 1 cedula de 100   
            }
            while(trocoint>=50){
                    cout<<"C 50"<<endl;
                    trocoint -=50;     // diminuir 50 do troco toda vez que for contabilizado 1 cedula de 50   
            }
            while(trocoint>=20){
                    cout<<"C 20"<<endl;
                    trocoint -=20;    // diminuir 20 do troco toda vez que for contabilizado 1 cedula de 20   
            }
            while(trocoint>=10){
                    cout<<"C 10"<<endl;
                    trocoint -= 20;  // diminuir 10 do troco toda vez que for contabilizado 1 cedula de 10   
            }
            while(trocoint>=5){
                    cout<<"C 5"<<endl;
                    trocoint -= 5;   // diminuir 5 do troco toda vez que for contabilizado 1 cedula de 5   
            }
            while(trocoint>=2){
                    cout<<"C 2"<<endl;
                    trocoint -= 2;   // diminuir 2 do troco toda vez que for contabilizado 1 cedula de 2   
            }
            centavos = centavos +(trocoint*100); //como nao existe cedula de 1 real, somar o possivel resto do troco em real para centavos de real
            centavosint = int(centavos);
            while(centavosint>=100){
                cout<<"M 100"<<endl;
                centavosint -=100;      // diminuir 100 do troco toda vez que for contabilizado 1 moeda de 100 centavos(1 real)  
            }
            while(centavosint>49){
                cout<<"M 50"<<endl;
                centavosint -= 50;     // diminuir 50 do troco toda vez que for contabilizado 1 moeda de 50 centavos  
            }
             while(centavosint>24){
                cout<<"M 25"<<endl;
                centavosint -=25;     // diminuir 100 do troco toda vez que for contabilizado 1 moeda de 25 centavos    
            }   
            while(centavosint>9){
                cout<<"M 10"<<endl;
                centavosint -=10;     // diminuir 100 do troco toda vez que for contabilizado 1 moeda de 10 centavos  
            }
            while(centavosint>4){ 
                cout<<"M 5"<<endl;
                centavosint -=5;      // diminuir 100 do troco toda vez que for contabilizado 1 moeda de 5 centavos    
            }
            while(centavosint>=1){
                cout<<"M 1"<<endl;
                centavosint -=1;      // diminuir 100 do troco toda vez que for contabilizado 1 moeda de 1 centavo    
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