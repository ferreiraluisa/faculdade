#include <iostream>
using namespace std;

int main(){
    int n;
    int div,i,soma;

    cin>>n;
    soma = 0;

    for(i=1;i<=n;i++){
        div = n%i;
        if(div==0 && i!=n)
            soma = soma + i;
    }
    if(soma==n)
        cout<<"SIM"<<endl;
    else
        cout<<"NAO"<<endl;

    return 0;

}