#include "funcionario.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>

void Funcionario::calcular_gastos(){
    std::ifstream fin("entrada.txt");
    std::ofstream fout("saida.txt");

    if(!fin.is_open()){
        std::cerr<<"ERRO!Nao foi possivel abrir arquivo de entrada"<<std::endl;
        exit(1);
    }
    if(!fout.is_open()){
        std::cerr<<"ERRO!Nao foi possivel abrir arquivo de saida"<<std::endl;
        exit(1);
    }


    std::vector<std::string> phrases;
    std::vector<double> numbers;

    char linha[200];
    char *tok;

    while(true){
        fin.getline(linha,150);
        std::string aux = linha;
        phrases.push_back(aux);
        bool number = false;
        int cont = 0;

        tok = strtok(linha," ");


        while(tok != NULL){
            tok = strtok(NULL," ");
            cont++;
            if(cont==2){
                numbers.push_back(atof(tok));
            }
        }
        
        if(fin.eof() || fin.fail()){
            break;
        }
    }
    double gasto_total = 0;
    double num_funcionarios = numbers.size();

    for(int i=0;i<numbers.size();i++){
        gasto_total += numbers[i];
    }

    fout<<"Nro. Funcionario Gasto %"<<std::endl;

    for(int i=0;i<numbers.size();i++){
        fout<<i+1<<" "<<phrases[i]<<ceil(numbers[i]*100/gasto_total)<<"%"<<std::endl;
    }

    fout<<"Gasto mensal total: R$"<<gasto_total<<std::endl;
    fout<<"Gasto medio por funcionario: R$"<<gasto_total/num_funcionarios<<std::endl;

    fin.close();
    fout.close();
}