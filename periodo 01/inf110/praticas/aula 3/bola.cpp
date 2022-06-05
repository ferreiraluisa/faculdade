#include <iostream>
using namespace std;

int main () {
    int diametro;
    int a,l,p;

    cin>>diametro;
    cin>>a>>l>>p;
    
    if (diametro<=a && diametro<=l && diametro<=p)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;
    
    return 0;
}