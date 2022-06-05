#include <iostream>
using namespace std;

int main () {
    char v[100];
    int n;
    
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=(n-1);i>=0;i--)
        cout<<v[i];
    
    return 0;
}