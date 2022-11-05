#include <iostream>
using namespace std;

bool divresto(int a, int b, int &c, int &d){
    if(b==0){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(divresto(a,b,c,d)){
            cout<<a/b<<" "<<a%b<<endl;
        }
        else{
            cout<<"indefinido"<<endl;
        }
    }
    return 0;
}