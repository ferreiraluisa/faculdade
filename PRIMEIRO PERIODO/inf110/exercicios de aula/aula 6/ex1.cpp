#include <iostream>
using namespace std;

int main (){
    double altura,massa,imc;

    cout<<"Digite sua altura, em metros: ";
    cin>>altura;
    cout<<"E seu peso, em kg: ";
    cin>>massa;

    imc = massa/(altura*altura);

    if (imc<18.5)
        cout<<"ABAIXO DO PESO."<<endl;
    else if(imc<25)
        cout<<"PESO NORMAL."<<endl;
    else if(imc<30)
        cout<<"ACIMA DO PESO."<<endl;
    else 
        cout<<"OBESIDADE."<<endl;

    return 0;

}