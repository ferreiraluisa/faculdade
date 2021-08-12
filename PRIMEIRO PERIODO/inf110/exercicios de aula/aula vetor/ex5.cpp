#include <iostream>
using namespace std;

int main () {
    long int v[1000000];
    int n;

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>v[i];
    
    for(int passo=0;passo<n-1;passo++){
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<v[i]<<" "<<endl;
    
    return 0;
}