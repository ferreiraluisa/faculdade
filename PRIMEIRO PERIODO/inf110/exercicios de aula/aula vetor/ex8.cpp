#include <iostream>
using namespace std;

int main (){
    int n;
    cin>>n;
    int v[n];
    int a;
    
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int laco=0;laco<n-1;laco++){
        for(int i=0;i<n-1;i++)
            if(v[i]>v[i+1]){
                a = v[i];
                v[i] = v[i+1];
                v[i+1]=a;
            }
    }
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    
    return 0;
}