#include <iostream>
using namespace std;

int main () {
    int i,div,cont;
    int n;

    cin>>n;
    cont = 0;

    for(i=1;i<=n;i++){
        div = n%i;
        if(div == 0)
            cont++;    
        }
    if(cont==2 && n !=1)
        cout<<"Primo."<<endl;
    else
        cout<<"Nao primo."<<endl;
    return 0;
    

}