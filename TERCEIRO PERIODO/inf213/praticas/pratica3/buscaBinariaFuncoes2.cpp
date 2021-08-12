#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int taxaVideo,taxaDownload,tamanho;

bool consigoAssistirSemPausas(int tempoCarregamento) {
	bool resposta = true;
	int tempoCarregado = taxaDownload * (tempoCarregamento);
	for(int i=0;i<tamanho;i++){
		if(tempoCarregado + taxaDownload < taxaVideo) resposta = false;
		tempoCarregado = tempoCarregado + taxaDownload - taxaVideo;
		
	}

	return resposta;

}

int main() {
    std::cin>>taxaVideo>>taxaDownload>>tamanho;


    //Busca Sequencial
    for(int i=0;i<50000;i++){
        if(consigoAssistirSemPausas(i)==true){
            std::cout<<i<<std::endl;
            break;
        }
    }

    

    return 0;
}