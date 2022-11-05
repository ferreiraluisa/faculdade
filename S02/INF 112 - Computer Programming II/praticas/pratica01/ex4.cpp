//Luisa de Souza Ferreira - 102026 - Exercicio04
#include <iostream>
using namespace std;

int main(){
    char str [] = "abc teste";
    char *ptr = str;
    char *ptr2 = str;

    for(ptr; *ptr ; ptr++){

    }

    for(ptr; ptr != (ptr2-1); ptr--){
        cout<<*ptr;
    }

    return 0;
}