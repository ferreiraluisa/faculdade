//calcular se o ano e bissexto ou nao
#include <iostream>
using namespace std;

int main () {
    int ano;
    
    cout<<"Digite o ano: ";
    cin>>ano;

    if ((ano%4==0) && (ano%100!=0))
        cout<<"O ano "<<ano<<" e bissexto"<<endl;
    else
        cout<<"O ano "<<ano<<" nao e bissexto"<<endl;
    
    return 0;
}