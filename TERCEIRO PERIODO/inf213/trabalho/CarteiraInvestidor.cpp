#include "CarteiraInvestidor.h"

CarteiraInvestidor::CarteiraInvestidor(){
	acoes = new Acao[500000];
}

CarteiraInvestidor::~CarteiraInvestidor(){
	delete []acoes;
}

/*int CarteiraInvestidor::buscaBinTicker(string chave, int n){ -> para buscar o ticker no array de acoes pra ver se a acao ja foi incluida no array.
	int begin =0;
    int end = n;
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

void CarteiraInvestidor::armazenandoDadosAcoes(Operacoes *op, int m, Preco *preco, int n, Dividendo *dividendos,int o, Split splits, int p){ ->iria armazenar os dados das acoes, para facilitar na hora de buscar os dados, se o investidor tivesse comprado a PETR4 no dia 21/05/2021 ficaria mais facil consultar qual era a cotacao naquele dia da acao PETR4 e ate pra ver se existia dividendos ou nao. A funcao armazenandoDados travava o programa e eu nao entendi porque, ja que quando eu testei ela para somente uma acao ela funcionou. A complexidade dela é O(m*(n+p+o)),(m,n,p,o sao elementos da entrada) talvez fosse algo muito desgastante pra cpu ou eu errei algo que nao vi.
	int size = 0;
	for(int i=0;i < m ;i++){
		string ticker = op[i].getTicker();
		if(i == 0){
			acoes[size] = Acao(ticker, 0);
			acoes[size].armazenandoDados(preco,n,dividendos,o,splits,p);
			size++;
		}
		else{
			if(buscaBinTicker(ticker,size)== -1){
				acoes[size] = Acao(ticker, 0);
				size++;
			}
		}
	}
	sizeAcoes = size;
}
*/

