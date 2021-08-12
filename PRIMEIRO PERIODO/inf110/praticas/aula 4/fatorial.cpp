#include <iostream>
using namespace std;

int main (){
    int i,n;
    long long int fatorial;
    
    cin>>n;
    fatorial = 1;
    
    for(i=1;i<=n;i++)
        fatorial *= i;
    
    cout<<fatorial<<endl;

    return 0;
}