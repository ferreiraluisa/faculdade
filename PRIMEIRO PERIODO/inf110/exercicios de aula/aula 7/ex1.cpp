#include <iostream>
using namespace std;

int main () {
    int a,b;
    double media;

    cin>>a>>b;

    media=(a+b)/2;

    if((a+b)%2==0)
        cout<<media<<endl;
    else
        cout<<"Nao existe valor medio inteiro"<<endl;

    return 0;
}