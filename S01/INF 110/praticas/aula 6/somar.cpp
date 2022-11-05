#include <iostream>
using namespace std;

int main () {
    int n,soma,cont=0;
    cin>>n;
    int v[n];

    for(int i=0;i<n;i++)
        cin>>v[i];
    
    cin>>soma;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i]+v[j]==soma && i!=j)
                cont++;
        }
    }

    if(cont>=1)
        cout<<"SIM"<<endl;
    else
        cout<<"NAO"<<endl;

    return 0;

    

}