#include <iostream>
#include <cstdlib>
using namespace std;

void PreencheAleatorio(int *ptr, int n){
    for(int i=0;i<n;i++){
            ptr[i] = rand()%10;
        }
}

void Imprime(int *ptr, int n){
    for(int i=0; i<n;i++){
        if(i==n-1){
            cout<<ptr[i]<<endl;
        }
        else{
            cout<<ptr[i]<<" , ";
        }
    }
}

void ContaParImpar(int *ptr1, int *ptr2, int n, int &contpar, int &contimpar){
    for(int i=0;i<n;i++){
            if((ptr1[i] + ptr2[i])%2==0){
                contpar++;
            }
            else{
                contimpar++;
            }
        }
}



int main(){
    int n=1;

    while(true){
        cout<<"Digite quantas rodadas o jogador deseja simular: ";
        cin>>n;
        if(n<=0){
            break;
        }

        int *ptr1 = new int[n];
        int *ptr2 = new int[n];

        PreencheAleatorio(ptr1,n);
        PreencheAleatorio(ptr2,n);

        int contpar=0 , contimpar=0;

        
        ContaParImpar(ptr1,ptr2,n,contpar,contimpar);

        Imprime(ptr1,n);
        Imprime(ptr2,n);

        cout<<"Par = "<<contpar<<endl;
        cout<<"Impar = "<<contimpar<<endl;

        delete ptr1;
        delete ptr2;
    }

    return 0;


    
}