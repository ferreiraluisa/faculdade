#include <iostream>
using namespace std;

int main () {
    int notafinal,faltateorica,faltapratica;

    cin>>notafinal>>faltateorica>>faltapratica;

    if ((faltateorica)<=15 && (faltapratica)<=7){
        if(notafinal>=60)
            cout<<"Aprovado"<<endl;
        else if(notafinal>=40)
            cout<<"Final"<<endl;
        else if(notafinal<40)
            cout<<"Reprovado"<<endl;
    }
    else
        cout<<"Reprovado"<<endl;
    
    return 0;
    
}