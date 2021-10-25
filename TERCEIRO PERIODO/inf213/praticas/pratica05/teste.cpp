#include <iostream>
using namespace std;

void imprime(int *v, int n){
    for(int i=0;i<n;i++) cout<<v[i]<<" "; cout<<endl;
}

int main(){
    int cont = 0;
    int n=5;
    int *v = new int[n];
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 3;
    v[4] = 6;
	for(int i=0;i<n;i++){
        imprime(v,n);
        if(v[i] == 3){
           for(int j = i;j<n-1;j++) {
               int aux = v[j+1];
               v[j] = aux;
            }
            n--;
            i--; 
        }
        
    }
    
    imprime(v,n);
    cout<<cont;
}