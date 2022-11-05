#include "classeBase.h"
#include <iostream>
#include <cmath>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <sstream>


int main(int argc, char **argv){
    classeBase controle(argv[1],argv[2],argv[3],argv[4]);
    controle.lerArquivos();
    controle.ordenaArquivos();

    if(controle.getAuxOperacao() == 'Q'){
        for(int i=0;i<controle.getSizeOperacoes();i++){
            std::cout<<controle.consulta(i)<<"\n";
        
        }
    }
    return 0;

}