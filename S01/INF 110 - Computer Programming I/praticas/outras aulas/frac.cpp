#include <iostream>
using namespace std;

void somafrac(int na, int da, int nb, int db, int &nr, int &dr){
    int simp,aux;
    dr = da*db;
    nr = na*(dr/da) + nb*(dr/db);
    if(nr>=dr){
        for(int i=1;i<=nr;i++){
            if(nr%i==0 && dr%i==0){
                simp = i;
            }
        }
    }
    else{
        for(int i=1;i<=dr;i++){
            if(nr%i==0 && dr%i==0){
                simp = i;
            }
        }
    }
    if(simp>1){
        dr = dr/simp;
        nr = nr/simp;
    }
}
int main(){
    int na,da,nb,db,nr,dr;
    char a,b;
    cin>>na>>a>>da>>nb>>b>>db;

    somafrac(na,da,nb,db,nr,dr);

    cout<<na<<"/"<<da<<"+"<<nb<<"/"<<db<<"="<<nr<<"/"<<dr<<endl;

    return 0;
}
