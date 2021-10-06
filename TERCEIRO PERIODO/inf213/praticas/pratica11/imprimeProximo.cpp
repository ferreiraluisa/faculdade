#include <iostream>
#include "MySet.h"

int main(){
    char tipo;
    int number;
    MySet<int> dataBase;

    while(cin>>tipo>>number){
        if(tipo=='C'){
            dataBase.insert(number);
        }
        if(tipo=='S'){
            
        }
    }
}