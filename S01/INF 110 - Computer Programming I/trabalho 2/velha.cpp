#include <iostream>
using namespace std;

int main(){
    int m[3][3]={{0,0,0},{0,0,0},{0,0,0}}; //inicializando o tabuleiro do jogo da velha como todos espacos igual a 0
    char xo; //variavel tipo char que sinaliza se a jogada eh do jogador x ou o
    int p1,p2,a=0,n;
    int soma,contvelha=0;

    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>xo>>p1>>p2;
        if(xo=='x'){
            m[p1][p2]=1; //o numero 1 sinaliza que o espaco m[p1][p2] foi ocupado por x
        }
        else if(xo=='o'){
            m[p1][p2]=-1; // o numero -1 sinaliza que o espaco m[p1][p2] foi ocupado por o
        }
    }

//Iremos analisar 4 formas de ganhar o jogo: 
//1)Completando linhas;
//2)Completando colunas;
//3)Completando a diagonal principal;
//4)Completando a diagonal secundaria;

   for(int i=0;i<3;i++){ //completando linhas
       soma=0;
       for(int j=0;j<3;j++){
           soma += m[i][j]; //somar todos elementos da linha 0,1,2
       }
       if(soma==3){ //se a soma der 3, é porque todos os espacos da linha foram preenchidos com 1(x)
           cout<<"Venceu x!"<<endl;
       }
       else if(soma==-3){ //se a soma der -3, é porque todos os espacos da linha foram preenchidos com -1(o)
           cout<<"Venceu o!"<<endl;
       }
       else{ //se nenhum dos dois ganhar, contabilizar, usaremos isso no final
           contvelha++; //como o laco percorre 3 vezes a esse else, esse contvelha vale como 3 pra soma final
       }
   }

   for(int i=0;i<3;i++){ //completando colunas
       soma=0;
       for(int j=0;j<3;j++){
           soma += m[j][i]; //somar todos elementos da coluna 0,1,2
       }
       if(soma==3){ //se a soma der 3, é porque todos os espacos da coluna foram preenchidos com 1(x)
           cout<<"Venceu x!"<<endl;
       }
       else if(soma==-3){ //se a soma der -3, é porque todos os espacos da coluna foram preenchidos com -1(o)
           cout<<"Venceu o!"<<endl;
       }
       else{ //se nenhum dos dois ganhar, contabilizar, usaremos isso no final
           contvelha++; //como o laco percorre 3 vezes a esse else, esse contvelha vale como 3 pra soma final
       }
   }

   soma = 0; //resetando a variavel soma para seguirmos com a logica de somarmos os elementos

   for(int i=0;i<3;i++){
       soma += m[i][i];
   }
   if(soma==3){ //se a soma der 3, é porque todos os espacos da diagonal foram preenchidos com 1(x)
       cout<<"Venceu x!"<<endl;
   }
   else if(soma==-3){ //se a soma der -3, é porque todos os espacos da diagonal foram preenchidos com -1(o)
       cout<<"Venceu o!"<<endl;
   }
   else{
       contvelha++; //se nenhum dos dois ganhar, contabilizar, usaremos isso no final, como o for 
   }

   soma = 0; //resetando a variavel soma para seguirmos com a logica de somarmos os elementos

   for(int i=2;i>=0;i--){
       soma += m[a][i];
       a++;
   }
   if(soma==3){ //se a soma der 3, é porque todos os espacos da diagonal foram preenchidos com 1(x)
       cout<<"Venceu x!"<<endl;
   }
   else if(soma==-3){ //se a soma der -3, é porque todos os espacos da diagonal foram preenchidos com -1(o)
       cout<<"Venceu o!"<<endl;
   }
   else{
       contvelha++;  //se nenhum dos dois ganhar, contabilizar, usaremos isso no final
   }
   if(contvelha==8){ //se em nenhum caso o "x" ou o "o" ganha, entao o contvelha sera somado 1 oito vezes!
       cout<<"Velha!"<<endl;
   }
   return 0;


}