#include <iostream>
using namespace std;

long long int fatorial (int x) {
    long long int fat = 1;
    for(int i=2; i<=x; i++)
    fat *= i;
    return fat;
}


int main(){
    int n,k;
    
    cin>>n>>k;

    cout<<fatorial(n)/(fatorial(k)*fatorial(n-k))<<endl;
    
    return 0;
}