#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include "MyVec.h"
#include "Huffman.h"
using namespace std;
int main() {
int freqs[256] = {0};
freqs['A'] = 2;
freqs['B'] = 8;
freqs['C'] = 1;
freqs['D'] = 1;
HuffManTree arvore(freqs);
MyVec<unsigned char> in;
in.push_back('A');
in.push_back('B');
in.push_back('B');
in.push_back('C');
//A frequencia nao precisa ser necessariamente a mesma dos
//dados de entrada (nessa entrada a frequencia de B e'2, nao 8)
//O ideal eh que a frequencia seja a mesma! (isso poderia gerar uma compressao)
MyVec<bool> comprimido;
arvore.comprimir(comprimido, in);
for(int i=0;i<comprimido.size();i++)
cout << comprimido[i];
cout << endl;
//deveria imprimir: 1000110 (supondo que a arvore gerada foi igual a apresentada no roteiro)
MyVec<unsigned char> descomprimido;
arvore.descomprimir(descomprimido, comprimido);
for(int i=0;i<descomprimido.size();i++)
cout << descomprimido[i];
cout << endl;
//deveria imprimir: ABBC
}