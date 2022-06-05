//a ponte so deixa passar veiculos de ate 3m de largura e 80 ton, calcular se o veiculo pode passar na ponte
#include <iostream>
using namespace std;

int main (){
    int largura,peso;

    cout<<"Digite a largura do veiculo, em metros: ";
    cin>>largura;
    cout<<"Digite o peso do veiculo, em toneladas: ";
    cin>>peso;

    if (largura<=3 && peso<=80)
        cout<<"PASSE LIVRE!";
    else
        cout<<"LARGURA E PESO ULTRAPASSARAM DO LIMITE! PASSE NEGADO!";
    
    return 0;
}