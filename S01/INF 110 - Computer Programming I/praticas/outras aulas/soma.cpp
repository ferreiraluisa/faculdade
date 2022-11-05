#include <iostream>
using namespace std;

int main(){
    int n,x,cont=0;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cin>>x;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){
                if(a[i]+a[j]==x){
                    cont++;
                }
            }
        }
    }

    if(cont>=1){
        cout<<"SIM"<<endl;
    }
    else{
        cout<<"NAO"<<endl;
    }

    return 0;
}