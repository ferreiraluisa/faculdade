#include <iostream>
using namespace std;

int main () {
    double precoinicial,desconto,precofinal;
    char simounao;

    cout<<"Digite o preco inicial do produto: ";
    cin>>precoinicial;
    cout<<"Possue desconto?[s/n] ";
    cin>>simounao;

    if (simounao=='s') {
        cout<<"Digite a % de desconto: ";
        cin>>(desconto);
        desconto = desconto/100;
        cout<<"O preco final eh "<<precoinicial-(precoinicial*desconto)<< " reais"<<endl;
    }
    else
        cout<<"O preco final eh "<<precoinicial<<endl;
    
    return 0;

}