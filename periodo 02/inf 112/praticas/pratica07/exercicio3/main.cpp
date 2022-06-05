#include "arquivoif.h"
#include <iostream>

int main(){
    ArquivoIF *obj = new ArquivoIF;

    obj->novo_relatorio();

    delete obj;

    return 0;
}