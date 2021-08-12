#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

//Busca binaria
//Pesquisa pelo elemento "chave" entre as posicoes begin e end (inclusive) do array 
//Retorna -1 se elemento nao esta no array
int buscaBin(int *array,int begin, int end, int chave) {
	if (begin > end) return -1;
	int meio = (end-begin)/2 + begin;
	if (array[meio] == chave)
		return meio;
	if (array[meio] > chave)
		return buscaBin(array,begin, meio-1, chave); 
	return buscaBin(array,meio+1, end, chave); 	
}

//Busca binaria iterativa
//Pesquisa pelo elemento "chave" entre as posicoes begin e end (inclusive) do array 
//Retorna -1 se elemento nao esta no array
int buscaBinIterativa(int *array,int begin, int end, int chave) {
	while(begin <= end) {
		int meio = (end-begin)/2 + begin;
		if (array[meio] == chave)
			return meio;
		if (array[meio] > chave) 
			end =  meio-1; 
		else begin = meio+1; 
	}
	return -1;	 	
}