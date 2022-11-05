#include <iostream>
using namespace std;

void limparArray(int *v, int n){
    for(int i=0;i<n;i++) v[i] = 0;
}
void merge(int *v, int p, int q, int r, int *aux) {
    int tam = r-p;
    int i = p; //cursor 1
    int j = q; //cursor 2
    int k = 0; //cursor para aux
    while(i < q && j < r) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while(i < q)
        aux[k++] = v[i++];
    while(j < r)
        aux[k++] = v[j++];
    for(k = 0; k < tam; k++)
        v[p+k] = aux[k];
    limparArray(aux, tam);
}


int main(){
    int *aux = new int[5];
    int v[10] = {9,6,5,0,1,3,2,8,7,4};
    merge(v,0,4,10,aux);
    for(int i=0;i<10;i++) cout<<v[i]<<" ";
    delete []aux;
}