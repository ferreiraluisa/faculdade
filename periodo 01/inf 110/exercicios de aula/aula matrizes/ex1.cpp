#include <iostream>
using namespace std;

int main () {
    double notas [5][3];
    double soma,media,s1,s2,s3;

    soma = 0;
    media = 0;

    for(int i=0;i<5;i++){
        for(int b=0;b<3;b++){
            cin>>notas[i][b];
            soma +=notas[i][b];
        }
        media += soma;
       
    }
    media = media/5;

    cout<<"Aluno 1 - "<<notas[1][0]<<" "<<notas[1][1]<<" "<<notas[1][2]<<" Total: "<<notas[1][0]+notas[1][1]+notas[1][2]<<endl;
    cout<<"Aluno 2 - "<<notas[2][0]<<" "<<notas[2][1]<<" "<<notas[2][2]<<" Total: "<<notas[2][0]+notas[2][1]+notas[2][2]<<endl;
    cout<<"Aluno 3 - "<<notas[3][0]<<" "<<notas[3][1]<<" "<<notas[3][2]<<" Total: "<<notas[3][0]+notas[3][1]+notas[3][2]<<endl;
    cout<<"Aluno 4 - "<<notas[4][0]<<" "<<notas[4][1]<<" "<<notas[4][2]<<" Total: "<<notas[4][0]+notas[4][1]+notas[4][2]<<endl;
    cout<<"Aluno 5 - "<<notas[5][0]<<" "<<notas[5][1]<<" "<<notas[5][2]<<" Total: "<<notas[5][0]+notas[5][1]+notas[5][2]<<endl;

    return 0;
}