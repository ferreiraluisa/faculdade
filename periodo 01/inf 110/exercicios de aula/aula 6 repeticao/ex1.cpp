#include <iostream>
using namespace std;

int main () {
    int cont,n,soma,num;

    cout<<"Digite quantos numeros impares voce deseja saber: ";
    cin>>n;
    cont = 0;
    soma = 0;
    
    while(cont<n) {
        num = (2*cont) + 1;
        cont++;
        soma += num;
        cout<<num<<" ";
    }
    cout<<"\n";
    cout<<"A soma dos "<<n<<" primeiros numeros impares eh: "<<soma<<endl;

    return 0;
        
}


