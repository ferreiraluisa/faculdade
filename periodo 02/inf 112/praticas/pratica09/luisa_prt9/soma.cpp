#include "soma.h"

int Soma::soma_recursiva(int m, int n){
    if(m == n){
        return m;
    }
    else{
        return m + soma_recursiva(m+1,n);
    }
}