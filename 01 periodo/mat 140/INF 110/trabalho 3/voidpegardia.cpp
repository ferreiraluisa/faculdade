#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


void pegardia(int diasdomes,int &dia,char nome[],int m){
    int cont = 0;
    char mes[12][100]={{"Janeiro"},{"Fevereiro"},{"Março"},{"Abril"},{"Maio"},{"Junho"},{"Julho"},{"Agosto"},{"Setembro"},{"Outubro"},{"Novembro"},{"Dezembro"}};
    char frase[300],d[20];
    strcpy(d,"");
    strcpy(frase,"");
    cout<<nome<<" : ";
    cin.getline(frase,300);
    for(int i=0;i<strlen(frase);i++){
        if(isdigit(frase[i])){
            cont++;
            char aux[10] = {frase[i]};
            strcat(d,aux);
            strcpy(aux,"");
        }
    }
     if(cont==0){
        cout<<"CosmosBot : Você não digitou nenhum número, por favor, escreva um número novamente por meio de algarismos! "<<endl;
        pegardia(diasdomes,dia,nome,m);
    }
    else{
        if(atoi(d)>diasdomes){
            cout<<"CosmosBot : "<<mes[m-1]<<" não tem "<<atoi(d)<<" dias. Me fale um dia do mês de "<<mes[m-1]<<endl;
            pegardia(diasdomes,dia,nome,m);
        }
        else{
            dia = atoi(d);
        }
    }
}

int main(){
    int dia;
    char nome[50] = "Luisa";


    cout<<"CosmosBot : Me fale um dia desse mês!"<<endl;
    pegardia(31,dia,nome,1);

    dia = dia + 1;

    cout<<dia<<endl;

}