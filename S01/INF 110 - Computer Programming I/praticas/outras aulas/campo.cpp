#include <iostream>
using namespace std;

int main(){
    int l,c,b,x,y;
    cin>>l>>c>>b;
    int a[l][c];

    l += 2;
    c += 2;

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            a[i][j]=0;
        }
    }

    for(int i=0;i<b;i++){
        cin>>x>>y;
        a[x][y] = -10;
        a[x][y-1] +=1;
        a[x][y+1] +=1;
        a[x-1][y] +=1;
        a[x-1][y-1] +=1;
        a[x-1][y+1] +=1;
        a[x+1][y] +=1;
        a[x+1][y+1] +=1;
        a[x+1][y+1] +=1;

    }

    for(int i=0;i<l-1;i++){
        for(int j=0;j<c-1;j++){
            if(a[i][j]<0){
                cout<<"B";
            }
            else if(a[i][j]==0){
                cout<<"-";
            }
            else{
                cout<<a[i][j];
            }
        }
        cout<<"\n";
    }

    return 0;
}