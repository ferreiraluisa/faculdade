#include <iostream>
using namespace std;

int main(){
    int _;
    _ = 2;
    cout<<_<<endl;
    cout<<"linda"<<endl;
    int cont = 0;
    for(int i=7;i<1000;i+=7){
       cont++;
    }
    cout<<cont<<endl;
    cont = 0;
    for(int i=11;i<1000;i+=11){
       cont++;
    }
    cout<<cont<<endl;
    cont = 0;
    for(int i=11;i<1000;i+=11){
       if(i%7==0) cont++;
    }
    cout<<cont<<endl;
    cont = 0;
    for(int i=7;i<1000;i+=7){
       if(i%11!=0) cont++;
    }
    cout<<cont<<endl;   
}