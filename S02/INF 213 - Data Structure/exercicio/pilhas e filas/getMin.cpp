#include <iostream>
#include "MyStack.h"

using namespace std;

int main(int argc, char const *argv[]){
    MyStack<int> pilha;
    pilha.push(27);
    pilha.push(42);
    pilha.push(-2);
    pilha.push(12);
    pilha.push(0);

    cout<<"menor elemento da pilha: "<<pilha.getMin()<<endl;

}