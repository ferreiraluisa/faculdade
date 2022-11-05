#include "mdc.h"

int MDC::mdc_recursiva(int x, int y){
    if (y==0){
        return x;
    }
    else
    {
        return mdc_recursiva(y,x % y);
    }

}