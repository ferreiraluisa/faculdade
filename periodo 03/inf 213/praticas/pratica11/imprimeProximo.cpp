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
            typename MySet<int>::iterator it = dataBase.find(number);
            if(it == dataBase.end()){ //end() retorna null, poderia bota
                cout<<"FALHA"<<endl;
            }
            else if(++it == dataBase.end()){
                cout<<"FALHA"<<endl;
            }
            else{
                cout<<*it<<endl;
            }
        }
    }
}