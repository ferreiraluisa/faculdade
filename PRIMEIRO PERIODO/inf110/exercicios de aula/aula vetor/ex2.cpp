#include <iostream>
using namespace std;

int main() {

int a;
double preco[10];
double quantidade[10];
double total,soma;

total = 0;

cin>>a;

for(int i=0;i<a;i++){
    cin>>preco[i];
    cin>>quantidade[i];
    soma = preco[i] * quantidade[i];

    total =+ soma;
} 

for(int i=0;i<a;i++)
        cout<<preco[i]<<" * "<<quantidade[i]<<endl;

cout<<"Preco total a pagar: R$ "<<total<<endl;

return 0;

}