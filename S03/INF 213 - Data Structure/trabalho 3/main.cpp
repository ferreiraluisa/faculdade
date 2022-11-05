#include <iostream>
#include <fstream>
#include "Huffman.h"
using namespace std;

int main(int argc, char const **argv)
{
    
    MyVec<unsigned char> descomprimido;
    MyVec<bool> comprimido;

    if(*argv[1] ==  'c'){
        int freqs[256] = {0};
        char c;
        int qtdeBits;
        ifstream entradaPath(argv[2]);
        ofstream saidaPath(argv[3]);
        if(entradaPath.peek() == ifstream::traits_type::eof()) return 0; //ve se o arquivo está vazio
        if(entradaPath.is_open()){
            while(entradaPath.get(c)){
                unsigned char auxC = c;
                freqs[auxC]++;
                descomprimido.push_back(auxC);
            }
        }
        HuffManTree comprimeArquivo(freqs);
        //colocar o freqs dentro do arquivo comprimido
        comprimeArquivo.comprimir(comprimido, descomprimido);
        qtdeBits = comprimido.size();
        //usei aula de inf213 para conseguir fazer isso
        saidaPath.write(reinterpret_cast<char*>(freqs),256*sizeof(int));
        saidaPath.write(reinterpret_cast<char*>(&qtdeBits),sizeof(int));
        char bit = 0;
        int pos = 0;
        for(int i=0;i<qtdeBits;i++){
            if(i%8==0 && i!=0){//quando desse 8(numero de quantidade de bits em 1byte, armazena em um char)
                saidaPath.write(&bit,1);
                bit = 0;
                pos = 0;
            }
            if(comprimido[i]) bit = bit | (comprimido[i]<<pos);
            pos++;
        }
        if(bit!=0){
            saidaPath.write(&bit,1);
        }
    }
    else if(*argv[1] == 'd'){
        int freqs[256] = {0};
        int cont = 0;
        int qtdeBits;
        int qtdeBytes;
        bool b;
        ifstream entradaPath(argv[2]);
        ofstream saidaPath(argv[3]);
        if(entradaPath.peek() == ifstream::traits_type::eof()) return 0; //ve se o arquivo está vazio
        if(entradaPath.is_open()){
            entradaPath.read(reinterpret_cast<char*>(freqs),256*sizeof(int));
            entradaPath.read(reinterpret_cast<char*>(&qtdeBits),sizeof(int));

            qtdeBytes = ((qtdeBits+7)/8);//soma com +7, pra sempre quando um número que nao for divisivel por 8 der (n/8)+1 (arrendonar pra cima)
            for(int i=0;i<qtdeBytes;i++){
                char c = 0;
                entradaPath.read(&c,1);
                for(int j=0;j<8;j++){
                    if(comprimido.size() == qtdeBits) break;
                    comprimido.push_back((c & (1 << j)) != 0); //peguei como base a sua resposta pro Felipe Pereira Ferreira no Moodle na aba de perguntas do trabalho
                }
            }
        }
        //ler os primeiros 256 caracteres do arquivo comprimido e botar ele num vetor de int para criar a arvore
        HuffManTree descomprimeArquivo(freqs);
        descomprimeArquivo.descomprimir(descomprimido,comprimido);
        for(int i=0;i<descomprimido.size();i++){
            char aux = descomprimido[i];
            saidaPath.write(&aux,1);
        }
    }

    return 0;
}
