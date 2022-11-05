#include "power.h"

int Power::potencia_recursiva(int k, int n){
    if(n==1){
        return k;
    }
    else{
        return k * potencia_recursiva(k,n-1);
    }
}