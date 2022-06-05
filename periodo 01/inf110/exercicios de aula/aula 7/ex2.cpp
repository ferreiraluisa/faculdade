#include <iostream>
using namespace std;

int main () {
    int i;
    int n;

    cin>>n;

    for(i=0;i<=n;i++){
        if(i%2==0)
            cout<<i<<" ";
    }
    
    return 0;
}