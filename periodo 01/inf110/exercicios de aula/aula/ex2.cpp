#include <iostream>
using namespace std;

int main () {
    int n,i,j,div,cont;

    cin>>n;

    for(i=1;i<=n;i++){
        cont = 0;
        for(j=1;j<=i;j++){
            if(i%j==0 )
                cont++;
        }
        if(cont==2)
            cout<<i<<" ";
    }
    return 0;
}
