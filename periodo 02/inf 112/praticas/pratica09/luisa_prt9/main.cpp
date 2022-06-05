#include "soma.h"
#include "power.h"
#include "mdc.h"
#include <iostream>

int main(){
    Soma obj;
    Power obj2;
    MDC obj3;

    std::cout<<obj.soma_recursiva(1,4)<<std::endl;
    std::cout<<obj2.potencia_recursiva(2,3)<<std::endl;
    std::cout<<obj3.mdc_recursiva(16,36)<<std::endl;

    return 0;
}