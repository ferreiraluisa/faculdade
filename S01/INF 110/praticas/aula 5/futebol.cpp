#include <iostream>
using namespace std;

int main () {
    int num,id,limite;
    int idade;
    int maior,menor;

    maior=0;
    menor=0;

    cin>>num>>id>>limite;

    for(int i=0;i<num;i++){
        cin>>idade;
        if(idade>=id)
            maior++;
        if(idade<id)
            menor++;
    }
    if(maior>limite)
        cout<<"Nao aceito."<<endl;
    else
        cout<<"Aceito."<<endl;

    return 0;


}