//Luisa de Souza Ferreira - 102026 - Exercicio 01
#include <iostream>
using namespace std;

void leinteiro1(int &a, int &b){ //por referencia
    cin>>a>>b;
}

void leinteiro2(int *a,int *b){ //por ponteiros
    cin>>*a>>*b;
}

int main(){
    int a,b,c,d;

    cout<<"Digite dois numeros inteiros: ";
    leinteiro1(a,b);
    cout<<a<<" "<<b<<endl;
    cout<<"Digite outros dois numeros inteiros: ";
    leinteiro2(&a,&b);
    cout<<a<<" "<<b<<endl;

    return 0;

}