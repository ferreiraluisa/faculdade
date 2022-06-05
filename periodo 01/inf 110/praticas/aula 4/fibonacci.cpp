#include <iostream>
using namespace std;

int main() {
    int i,n,cont;
    long long int t1,t2,t3;
    
    cont = 0;
    t1=0;
    t2=1;

    cin>>n;
    if(n==0)
        cout<<t1<<endl;
    else{
    while(cont<=(n-2)){
        cont++;
        t3 = t1+t2;
        t1 = t2;
        t2 = t3;
    }
    cout<<t2<<endl;

    }
    return 0;

}