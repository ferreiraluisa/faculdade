#include "arquivoif.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>

void ArquivoIF::novo_relatorio(){
    std::ifstream fin("entrada.txt");
    std::ofstream fout("ips.txt");

    std::vector<std::string> validos;
    std::vector<std::string> invalidos;

    if(!fin.is_open()){
        std::cerr<<"ERRO!Nao foi possivel abrir arquivo de entrada"<<std::endl;
        exit(1);
    }
    if(!fout.is_open()){
        std::cerr<<"ERRO!Nao foi possivel abrir arquivo de saida"<<std::endl;
        exit(1);
    }

    while(true){
        char linha[100];
        std::string aux;
        fin.getline(linha,30);
        aux = linha;
        char *tok = strtok(linha, ".");
        bool valido = true;

        while(tok != NULL){
            int num = atoi(tok);
            if(num<0 || num>255){
                valido = false;
            }
            tok = strtok(NULL, ".");
        }

        if(valido){
            validos.push_back(aux);
        }
        else{
            invalidos.push_back(aux);
        }

        if(fin.eof()){
            break;
        }
    }
    fout<<"[Enderecos validos: ]"<<std::endl;
    for(int i=0;i<validos.size();i++){
        fout<<validos[i]<<std::endl;
    }
    fout<<"\n";
    fout<<"[Enderecos invalidos: ]"<<std::endl;
    for(int i=0;i<invalidos.size();i++){
        fout<<invalidos[i]<<std::endl;
    }

    fin.close();
    fout.close();
}