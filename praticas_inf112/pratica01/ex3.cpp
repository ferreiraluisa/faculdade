//Luisa de Souza Ferreira - 102026 - Exercicio 03
#include <iostream>
using namespace std;

struct Jogador {
    int pontos ;
    int x , y ;
};

void leDadosJogador(Jogador *jog){
    for(int i=0;i<5;i++){
        cin>>(*(jog+i)).pontos>>(*(jog+i)).x>>(*(jog+i)).y;
    }
}

int main(){
    Jogador jog[5];
    Jogador *ptr = &(jog[0]);

    leDadosJogador(ptr);

    for(int i=0;i<5;i++){
        cout<<"Jogador "<<i+1<<" -> Pontos: "<<jog[i].pontos<<" X: "<<jog[i].x<<" Y: "<<jog[i].y<<endl;
    }

    return 0;
}