#include "CarteiraInvestidor.h"

CarteiraInvestidor::CarteiraInvestidor(){}

CarteiraInvestidor::CarteiraInvestidor(int n){
    acoes = new Acao[n];
}

CarteiraInvestidor::~CarteiraInvestidor(){
    delete []acoes;
}
int CarteiraInvestidor::buscaBinAcao(string chave){
    int begin =0;
    int end = getSizeOperacoes();
    while(begin <= end) {
		int meio = (end-begin)/2 + begin;
		if (acoes[meio].getTicker() == chave)
			return meio;
		if (acoes[meio].getTicker() > chave) 
			end =  meio-1; 
		else begin = meio+1; 
	}
	return -1;	 
}
int CarteiraInvestidor::dataToInt(string data){
    data.erase(data.begin()+4);
    data.erase(data.begin()+6);

    return stoi(data);
}
int CarteiraInvestidor::buscaBinData(int chave, int pos){
    int begin =0;
    int end = getSizeOperacoes();
    while(begin <= end) {
		int meio = (end-begin)/2 + begin;
		if (dataToInt(acoes[pos].getPrecoAcao()[meio].getData()) == chave)
			return meio;
		if (dataToInt(acoes[pos].getPrecoAcao()[meio].getData()) > chave) 
			end =  meio-1; 
		else begin = meio+1; 
	}
	return -1;	 
}
void CarteiraInvestidor::compraVenda(){
    for(int i=0;i<getSizeOperacoes();i++){
        int j=0;
        if(acaoRepetida(getArrayOperacoes()[i].getTicker())){
            int pos = buscaBinAcao(getArrayOperacoes()[i].getTicker());
            string data = getArrayOperacoes()[i].getData();
            int dataInt = dataToInt(getArrayOperacoes()[i].getData());
            int cotacao = acoes[pos].getPrecoAcao()[buscaBinData(dataInt,pos)].getPreco();
            if(getArrayOperacoes()[i].getOperacaoSecundaria() == 'V'){
                acoes[pos]._quantidade -= getArrayOperacoes()[i].getQuantidade();
                this->_custoCompra -= ( getArrayOperacoes()[i].getQuantidade() * cotacao);
                this->patrimonio -= ( getArrayOperacoes()[i].getQuantidade() * cotacao);
            }
            else{
                acoes[pos]._quantidade += getArrayOperacoes()[i].getQuantidade();
                this->_custoCompra += ( getArrayOperacoes()[i].getQuantidade() * cotacao);
                this->patrimonio += ( getArrayOperacoes()[i].getQuantidade() * cotacao);
                acoes[pos]._custoMedio = (acoes[pos]._custoMedio + _custoCompra)/acoes[pos]._quantidade;
            }
        }
        else{
            if(acaoRepetida(getArrayOperacoes()[i].getTicker())){
                Acao aux = Acao(getArrayOperacoes()[i].getTicker(),0,getSizeOperacoes());
                acoes[j] = aux;
                j++;
                int pos = buscaBinAcao(getArrayOperacoes()[i].getTicker());
                string data = getArrayOperacoes()[i].getData();
                int dataInt = dataToInt(getArrayOperacoes()[i].getData());
                int cotacao = acoes[pos].getPrecoAcao()[buscaBinData(dataInt,j)].getPreco();
                

            }
        }
    }
}

bool CarteiraInvestidor::acaoRepetida(string ticker){
    for(int i=0;i<getSizeOperacoes();i++){
        if(acoes[i].getTicker() == ticker) return true;
    }
    return false;
}