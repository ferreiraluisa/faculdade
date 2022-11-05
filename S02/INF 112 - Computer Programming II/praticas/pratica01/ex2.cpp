//Luisa de Souza Ferreira - 102026 - Exercicio 02
#include <iostream>
using namespace std;

int calculaTamanhoString1(char string[]){ // A)forma "tradicional"
    int cont=0;
    for(int i=0;string[i]!='\0';i++)
        cont++;
    return cont;
}

int calculaTamanhoString2(char * string){ //  B)utilizando ponteiros
    int i=0;
    char *ptr = string;
    for(i=0;*ptr!='\0';i++){
        ptr+=1;
    }
    return i;
}

int calculaTamanhoString3(char * string){ // C)apenas com variaveis do tipo char, sem usar notacao de arranjo([])
    char *ptr = string;                     
    for(ptr; *ptr; ptr++){
    }

    return (ptr - string);
}



int main(){
    char str[51];

    cout <<"Digite alguma string (com ate 50 caracteres): ";

    cin.getline(str,100);
    
    cout<<calculaTamanhoString1(str)<<" "<<calculaTamanhoString2(str)<<" "<<calculaTamanhoString3(str)<<endl;
}