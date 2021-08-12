#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double nota[10];
    double maior,menor,desvio,media;

    maior = 0;
    menor = 0;
    media = 0;
    desvio = 0;

    for(int i=0;i<10;i++){
        cin>>nota[i];
        if(nota[i]>=maior)
            maior=nota[i];
        if(nota[i]<=menor)
            menor=nota[i];
        media += nota[i];
    }
    cout<<"A maior nota eh "<<maior<<"."<<endl;
    cout<<"A menor nota eh "<<menor<<"."<<endl;
    cout<<"A media das notas eh "<<media/10<<endl;

    for(int a=0;a<10;a++){
        desvio += (nota[a]-media);
    }
    cout<<desvio<<endl;
    desvio = sqrt(desvio/10);

    cout<<"O desvio padrao das notas eh "<<desvio<<"."<<endl;



    return 0;

}