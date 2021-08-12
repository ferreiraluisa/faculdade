#include "keywords.h"
#include <cstring>
#include <fstream>
#include <vector>
#include <iostream>

KeyWords::KeyWords(std::string nome){
    nome_do_arquivo = nome;
}

void KeyWords::find_keywords(){
    std::ifstream fin(this->nome_do_arquivo,std::ios::in);
    std::ofstream fout("keywords.txt");

    if(!fin.is_open()){
        std::cerr<<"ERRO!Nao foi possivel abrir arquivo de entrada"<<std::endl;
        exit(1);
    }

    char frase[300];
    fin.getline(frase,300);
    char *tok;
    std::vector<std::string> words;
    std::vector<std::string> keywords;

    tok = strtok(frase, " ");
    int num_repeticoes[30] = {0};

    while(tok != NULL){
        words.push_back(tok);
        tok = strtok(NULL, " ");
    }
    bool palavra; 
    for(int i=0;i<=(words.size())-1;i++){
    	for(int j=i+1;j<=(words.size())-1;j++){
    		if(words[i]==words[j]){
                palavra = true;
                if(words[i][0]>=33 && words[i][0] <=47){
                    palavra = false;
                }
                if(palavra){
                    keywords.push_back(words[i]);
        }
            }
        }
    }

    fout<<"As palavras-chaves sao: ";
    for(int i=0;i<keywords.size();i++){
        if(i==keywords.size()-1)
            fout<<keywords[i]<<std::endl;
        else{
            fout<<keywords[i]<<" , ";
        }
    }

    fout<<"\n";

    fin.close();
    fout.close();
}