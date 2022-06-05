#include <iostream>
using namespace std;

int main() {
    int n,m,maior,c,d;
    cin>>n>>m;
    int a[n];
    int b[m];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    
    cout<<"{";

    for(c=0;c<n;c++){
        for(d=0;d<m;d++){
            if(a[c]==b[d])
                cout<<a[c]<<" ";
        }
    }
    cout<<"}"<<endl;

    return 0;
}