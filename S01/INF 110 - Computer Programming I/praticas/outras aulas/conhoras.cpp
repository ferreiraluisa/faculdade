#include <iostream>
using namespace std;

void convhoras(int s,int &h,int &m, int &se){
    h = s/3600;
    s = s%3600;
    m = s/60;
    se = s%60;
}

int main(){
    int seg,h,m,s;
    cin>>seg;
    convhoras(seg,h,m,s);
    if(h<10){
        cout<<"0"<<h<<":";
    }
    else{
        cout<<h<<":";
    }
    if(m<10){
        cout<<"0"<<m<<":";
    }
    else{
        cout<<m<<":";
    }
    if(s<10){
        cout<<"0"<<s;
    }
    else{
        cout<<s;
    }
    cout<<"\n";
    return 0;
}