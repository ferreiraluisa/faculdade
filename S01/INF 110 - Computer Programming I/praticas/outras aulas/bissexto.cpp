#include <iostream>
using namespace std;

bool bissexto(int n);

int main(){
    long int ano=2;

    while(true){
        cin>>ano;
        if(ano<0){
            break;
        }
        if(bissexto(ano)){
            cout<<"bissexto"<<endl;
        }
        else{
            cout<<"nao bissexto"<<endl;
        }
    }

    return 0;
}

bool bissexto(int n){
    bool p;
    if(n%4==0 && n%100!=0){
        p=true;
    }
    else if(n%400==0 && n%4==0){
        p=true;
    }
    else{
        p=false;
    }
    return p;
}
