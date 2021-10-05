#include <iostream>
#include "MyStack.h"

using namespace std;

int main(){
    MyStack<int> pilha;

    for(int i=5;i>=1;i--){
        pilha.push(i); // 1 2 3 .. n
    }

    MyStack<int> aux;
    MyStack<int> aux1;

    while(!pilha.empty()){
        aux.push(pilha.top());
        pilha.pop();
    }
    while(!aux.empty()){
        aux1.push(aux.top());
        aux.pop();
    }
    while(!aux1.empty()){
        pilha.push(aux1.top());
        aux1.pop();
    }
    while(!pilha.empty()){
        cout<<pilha.top()<<" ";
        pilha.pop();
    }
    cout<<endl;

}