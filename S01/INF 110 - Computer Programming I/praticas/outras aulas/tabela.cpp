#include <iostream>
using namespace std;

int main(){
    int d,f,a=0;
    cin>>d>>f;
    int m[d][f], mn[f][d];

    for(int i=0;i<d;i++){
        for(int j=0;j<f;j++){
            cin>>m[i][j];
        }
    }
    for(int i=0;i<f;i++){
        for(int j=0;j<d;j++){
            mn[i][j]=m[j][a];
        }
        a++;
    }
    for(int i=0;i<f;i++){
        for(int j=0;j<d;j++){
            if(j==d-1){
                cout<<mn[i][j];
            }
            else{
                cout<<mn[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}