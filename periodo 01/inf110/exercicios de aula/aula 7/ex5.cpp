#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int comput,pessoa;

    cout<<"//////JOGO DA ADVINHACAO\\\\\\\\\\\\"<<endl;
    comput = rand()%10;
    
    cout<<"Digite um numero inteiro de 0 a 9: "; 
    cin>>pessoa;

    if(pessoa==comput)
        cout<<"VOCE ACERTOU!!!EU REALMENTE PENSEI EM "<<comput<<"!!!!"<<endl;
    else
        cout<<"PERDEU!!!!!!EU PENSEI EM "<<comput<<endl;

    return 0; 



}