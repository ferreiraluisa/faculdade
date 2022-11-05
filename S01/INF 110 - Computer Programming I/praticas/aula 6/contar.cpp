#include <iostream>
using namespace std;

int main (){
    int n;
    cin>>n;
    int v[n];
    int maior,cont;

    cont = 0;
    
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    cin>>maior;

    for(int i=0;i<n;i++){
        if(v[i]>=maior)
            cont++;
    }

    cout<<cont<<endl;

    return 0;


}