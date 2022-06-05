#include <iostream>
using namespace std;

int main(){
    long int value1=200000,value2; 
    long int * longPtr; //letra A: Declare a variavel longPtr como um ponteiro para um objeto do tipo long.

    longPtr = &value1; //letra B: Atribua o endereco da variavel value1 a variavel ponteiro longPtr.

    cout<<"Valor do objeto apontado por longPtr: "<<*longPtr<<endl; //letra C

    value2 = *longPtr; //letra D : Atribua o valor do objeto apontado por longPtr a variavel value2.

    cout<<"Valor da variavel value2 : "<<value2<<endl; //letra E

    cout<<"Endereco da variavel value1 : "<<&value1<<endl; //letra F
    
    cout<<longPtr<<endl; //letra G. O valor impresso e o mesmo endereco do value1 por causa da atribuicao feita na letra B.


}