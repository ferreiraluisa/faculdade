#include <iostream>
#include "MyMap.h"

using namespace std;

int main(){
    MyMap<string, int> mapa;
    string palavra;
    int contador = 0;
    while(cin>>palavra){
        MyMapIterator<string,int > it = mapa.find(palavra);
            if(it == NULL){
                mapa.insert(pair<string,int>(palavra,contador));
                contador++;
            }
            else{
                mapa.insert(pair<string,int>(palavra,mapa[palavra]));
            }
            cout<<palavra<<" "<<mapa[palavra]<<endl;
    }

}