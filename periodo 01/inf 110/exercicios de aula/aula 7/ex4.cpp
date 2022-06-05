#include <iostream>
using namespace std;

int main() {
    char alf;

    cout<<"ALFABETO MAIUSCULO: ";

    for(alf=65;alf<=90;alf++)
        cout<<alf<<" ";
    
    cout<<"\nALFABETO MINUSCULO: ";

    for(alf=97;alf<=122;alf++)
        cout<<alf<<" ";
    
    return 0;
}