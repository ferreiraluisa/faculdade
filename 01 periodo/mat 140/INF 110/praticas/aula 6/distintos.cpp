#include <iostream>
using namespace std;

int main () {
    int n;
    cin>>n;
    int cont=1;
    int v[n];

    for(int i=0;i<n;i++)
        cin>>v[i];

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i] != v[j]){
                cont++;
            }
            break;
        }
    }
        cout<<cont<<endl;

    return 0;

    

}