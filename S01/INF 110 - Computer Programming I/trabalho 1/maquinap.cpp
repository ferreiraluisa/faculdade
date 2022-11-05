#include <iostream> 
using namespace std;

int main () {
    int produto;
    char mouc; //moeda ou cedula
    double valor,soma,troco,preco;
    valor = 1;
    soma = 0;

    cin>>produto;

    while(valor != 0){
        cin>>mouc>>valor;
        if(mouc == 'M' || mouc == 'm')
            valor = valor/100;     //quando selecionar moeda, divide por 100 porque eh centavo de real
        soma += valor;
    }
        
    if(produto==1)
        preco = 4.3; // batata shuffles R$4.30
    else if(produto==2)
        preco = 2.7;  // suco c mais R$2.70
    else if(produto==3)
        preco = 1.43;  // guarana qwerty R$1.43

    if(produto==1 || produto ==2 || produto==3){
        if(soma>=preco){
            troco = (soma - preco)*100; //multiplica por 100 para sair como numero inteiro como a saida do exercicio deseja 
            cout<<"Troco de "<<troco<<" centavos."<<endl;
        }
        else{
        cout<<"Saldo insuficiente."<<endl;
        }
    }
    else{
        cout<<"Produto inexistente."<<endl;
    }
    
    return 0;

}