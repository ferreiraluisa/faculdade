#include <iostream>
using namespace std;

int alturaMaxima(int *alturas){
    int maior = 0;
    for(int i=0;i<7;i++){
        if(alturas[i] > maior) maior = alturas[i];
    }

    return maior;
}

int main(){
    int alturas[7] = [1,3,7,9,16,2,5];
    cout<<alturaMaxima(alturas);
    }