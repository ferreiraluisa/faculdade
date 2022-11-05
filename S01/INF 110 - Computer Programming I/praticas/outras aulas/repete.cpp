#include <iostream>
using namespace std;

int main(){
    int t,n,cont=0,num;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n;
        num=0;
        cont=0;
        int m[n]={0};
        for(int j=0;j<n;j++){
            cin>>m[j];
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(k!=j){
                    if(m[j]==m[k]){
                        cont++;
                        num = m[j];
                    }
                }
            }
        }
        if(cont>=1){
            cout<<"SIM: "<<num<<endl;
        }
        else{
            cout<<"NAO"<<endl;
        }
    }
    return 0;
}