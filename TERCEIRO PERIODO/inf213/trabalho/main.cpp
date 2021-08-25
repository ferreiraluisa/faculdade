#include "classebase.h"
#include <iostream>
#include <cmath>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <sstream>

int main(){
    classeBase objeto("precos.csv","dividendos.csv","split.csv","operacoes.csv");
    objeto.lerPreco();
    objeto.lerDividendos();
    //objeto.lerOperacoes();
    //objeto.lerSplits();
    //objeto.ordenaArquivos();

    objeto.imprime();

    return 1;
    
}