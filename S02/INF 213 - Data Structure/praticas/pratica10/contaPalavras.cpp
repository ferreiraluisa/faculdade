#include <iostream>
#include <string>
#include "MyVecNewIterator.h"
#include "MySet.h"
using namespace std;

bool BuscarLista(MyVec<string> &lista, string elem){
    for(int i=0;i<lista.size();i++){
        if(elem == lista[i]) return true;
    }
    return false;
}

int main(int argc, char const **argv){
    int sizeUnicas=0;
    int sizeTotal=0;
    string tipoDeEd = argv[1];
    MyVec<string> lista;
    MySet<string> arvore;
    string palavra;

    if(tipoDeEd == "myvec"){
        while(cin>>palavra){
            if(BuscarLista(lista, palavra)){
                sizeTotal++;
            }
            else{
                lista.push_back(palavra);
            }
        }
        sizeTotal = sizeTotal + lista.size();
        sizeUnicas = lista.size();
    }
    if(tipoDeEd == "myset"){
        while(cin>>palavra){
            MySetIterator<string> it = arvore.find(palavra);
            if(it != NULL){
                sizeTotal++;
            }
            else{
                arvore.insert(palavra);
            }
        }
        sizeTotal = sizeTotal + arvore.size();
        sizeUnicas = arvore.size();
    }

    cout<<sizeTotal<<" "<<sizeUnicas<<endl;

}