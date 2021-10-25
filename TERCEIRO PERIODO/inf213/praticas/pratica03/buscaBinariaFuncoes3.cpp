#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int taxaVideo,taxaDownload,tamanho;

bool consigoAssistirSemPausas(long long tempoCarregamento) {
	bool resposta = true;
	long long tempoCarregado = taxaDownload * (tempoCarregamento);
	for(int i=0;i<tamanho;i++){
		if(tempoCarregado + taxaDownload < taxaVideo) resposta = false;
		tempoCarregado = tempoCarregado + taxaDownload - taxaVideo;
		
	}

	return resposta;

}

long long buscaBin(long long begin, long long end) {
	if (begin > end) return end;
	int meio = (end-begin)/2 + begin;
	if (consigoAssistirSemPausas(meio) == true){
        if(begin==end) return meio;
		else return buscaBin(begin,meio);
    }
	return buscaBin(meio+1, end); 	
}


int main() {
    std::cin>>taxaVideo>>taxaDownload>>tamanho;

    //Busca Sequencial
    /*for(int i=0;i<50000;i++){
        if(consigoAssistirSemPausas(i)==true){
            std::cout<<i<<std::endl;
            break;
        }
    }*/
    //Busca Binaria
    std::cout<<buscaBin(0,1000000000000)<<std::endl;


    return 0;
}