#include <iostream>
using namespace std;

int main(){
    int l,c,v,cont=0;
    cin>>l>>c;
    int m[l][c];

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }
    cin>>v;

    for(int i=0;i<l;i++){
        cont = 0;
        for(int j=0;j<c;j++){
            if(m[i][j]==v){
                cont++;
            }
        }
            cout<<cont<<endl;
    }

    return 0;

}