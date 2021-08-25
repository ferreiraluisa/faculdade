#include "classeBase.h"
#include <cstring>
#include <sstream>

//construtor
classeBase::classeBase(std::string arquivoPreco,std::string arquivoDividendos,std::string arquivoSplit,std::string arquivoOperacoes){
    _arquivoPreco = arquivoPreco;
    _arquivoDividendos = arquivoDividendos;
    _arquivoSplit = arquivoSplit;
    _arquivoOperacoes = arquivoOperacoes;

    precoAcoes = new Preco[500000];
    dividendoAcoes = new Dividendo[500000];
    splitAcoes = new Split[500000];
    operacoesBolsa = new Operacoes[500000];

}

//destrutor
classeBase::~classeBase(){
    delete []precoAcoes;
    delete []dividendoAcoes;
    delete []splitAcoes;
    delete []operacoesBolsa;
}

//Casting

//transformei a data para inteiro, porque é mais "barato" comparar inteiros do que strings na hora de fazer a ordenação
int classeBase::dataInt(std::string data){
    data.erase(data.begin()+4);
    data.erase(data.begin()+6);

    return stoi(data);

}

int classeBase::valorInt(std::string _preco){
    double aux = atof(_preco.c_str());
    aux = int((100 * aux) + 0.000001);
    return aux;

}

//Ler arquivos
//funcao responsavel por ler e armazenar os dados no arquivo que contem o preco das acoes, e isso sera armazenado num array de Preco(polimorfismo)
void classeBase::lerPreco(){ 
    int i=0;
    std::ifstream file(this->_arquivoPreco);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty) {
        while(file.good()){
        std::string ticker;
    
        std::string data;
    
        std::string preco;
    
        std::string lixo;
       
        std::getline(file,ticker,',');
        std::getline(file,data,',');
        std::getline(file,lixo,',');
        std::getline(file,lixo,',');
        std::getline(file,lixo,',');
        std::getline(file,preco,',');
        std::getline(file,lixo,',');
        std::getline(file,lixo,'\n');
        Preco aux(ticker,dataInt(data),valorInt(preco));
        precoAcoes[i] = aux;
        i++;
     }
    this->sizePreco = i;
    }
    
}
//funcao responsavel por ler e armazenar os dados no arquivo que contem os dividendos das acoes,se tiver, isso sera armazenado num array de Dividendos(polimorfismo)
void classeBase::lerDividendos(){ 
    int i=0;
    std::ifstream file(this->_arquivoDividendos);
    //https://www.daniweb.com/programming/software-development/threads/250669/check-if-file-is-empty
    
    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty){
        while(file.good()){
        std::string ticker;
    
        std::string data;
    
        std::string dividendo;
       
        std::getline(file,ticker,',');
        std::getline(file,data,',');
        std::getline(file,dividendo,'\n');
        Dividendo aux(ticker,dataInt(data),valorInt(dividendo));
        dividendoAcoes[i] = aux;
        i++;
     }
    this->sizeDividendo = i;
    }
}
//funcao responsavel por ler e armazenar os dados no arquivo que contem as splits das acoes,se ocorrer, isso sera armazenado num array de Splits(polimorfismo)
void classeBase::lerSplits(){ 
    int i=0;
    std::ifstream file(this->_arquivoSplit);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty){
        while(file.good()){
        std::string ticker;
    
        std::string data;
    
        std::string split;
       
        std::getline(file,ticker,',');
        std::getline(file,data,',');
        std::getline(file,split,'\n');
        Split aux(ticker,dataInt(data),split);
        splitAcoes[i] = aux;
        i++;
     }
    this->sizeSplit = i;
    }
}
//funcao responsavel por ler e armazenar os dados no arquivo que contem as operacoes da bolsa,se ocorrer, isso sera armazenado num array de Operacoes(polimorfismo)
void classeBase::lerOperacoes(){ 
    int i=0;
    std::ifstream file(this->_arquivoPreco);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty) {
        while(file.good()){
            std::string ticker;
        
            std::string data;
        
            std::string operacaoPrincipal;

            std::string operacaoSecundaria;

            if(i==0){ //essa vai ser a primeira linha
                std::getline(file,operacaoPrincipal,'\n');
                i--; //diminui um, pois o array de Operacoes que sera criado comeca do 0
            }
        
            std::getline(file,ticker,',');
            std::getline(file,data,',');
            std::getline(file,operacaoSecundaria,'\n');
            Operacoes aux(ticker,dataInt(data),operacaoSecundaria,operacaoPrincipal);
            operacoesBolsa[i] = aux;
            i++;
        }
        this->sizeOperacoes = i;
    }
    
}

//funcao maior que chama todas as outras so pra eu nao ter que ficar chamando toda hora na main
void classeBase::lerArquivos(){
    lerPreco();
    lerDividendos();
    lerSplits();
    lerOperacoes();
}
//ordenacao
void classeBase::ordenaPreco(Preco *v, int n){
    if(n == 0) return;
    Preco *aux = new Preco[n];
    ComparaPrecosTicket ordenaTicket;
    ComparaPrecosData ordenaData;
    mergeSort(v,0,n,ordenaData,aux);
    mergeSort(v,0,n,ordenaTicket,aux);
    delete []aux;
}
void classeBase::ordenaDividendo(Dividendo *v, int n){
    if(n == 0) return;
    Dividendo *aux = new Dividendo[n];
    ComparaDividendoTicket ordenaTicket;
    ComparaDividendoData ordenaData;
    mergeSort(v,0,n,ordenaData,aux);
    mergeSort(v,0,n,ordenaTicket,aux);
    delete []aux;
}
void classeBase::ordenaSplit(Split *v, int n){
    if(n == 0) return;
    Split *aux = new Split[n];
    ComparaSplitTicket ordenaTicket;
    ComparaSplitData ordenaData;
    mergeSort(v,0,n,ordenaData,aux);
    mergeSort(v,0,n,ordenaTicket,aux);
    delete []aux;
}
void classeBase::ordenaOperacoes(Operacoes *v, int n){
    if(n == 0) return;
    Operacoes *aux = new Operacoes[n];
    ComparaOperacoesTicket ordenaTicket;
    ComparaOperacoesData ordenaData;
    mergeSort(v,0,n,ordenaData,aux);
    mergeSort(v,0,n,ordenaTicket,aux);
    delete []aux;
}
void classeBase::ordenaArquivos(){
    ordenaPreco(precoAcoes, sizePreco);
    ordenaDividendo(dividendoAcoes, sizeDividendo);
    ordenaSplit(splitAcoes, sizeSplit);
    ordenaOperacoes(operacoesBolsa, sizeOperacoes);
}

//busca binaria
int classeBase::BuscaBin(Preco *array,int begin, int end,std::string chaveTicker, int chaveData) {
	if (begin > end) return end;
	int meio = (end-begin)/2 + begin;
	if (array[meio].getTicker() == chaveTicker){
        if(array[meio].getData()==chaveData) return array[meio].getPreco();
        else if(begin==end) return 0;
		else return BuscaBin(array,begin,meio,chaveTicker,chaveData);
    }
    //if (array[meio].getData() > chave)
	//	return buscaBin(array,begin, meio-1, chave); 
	return BuscaBin(array,meio+1, end, chaveTicker, chaveData); 	
}

//funcoes para teste!
void classeBase::imprime(){
    for(int i=0;i<sizePreco;i++){
        std::cout<<"---------------------"<<std::endl;
        std::cout<<this->precoAcoes[i].getTicker()<<std::endl;
        std::cout<<this->precoAcoes[i].getData()<<std::endl;
    }
}

//getters
Preco* classeBase::getArrayPreco(){
    return this->precoAcoes;
}
Dividendo* classeBase::getArrayDividendo(){
    return this->dividendoAcoes;
}
Split* classeBase::getArraySplit(){
    return this->splitAcoes;
}
Operacoes * classeBase::getArrayOperacoes(){
    return this->operacoesBolsa;
}
int classeBase::getSizeDividendo(){
    return this->sizeDividendo;
}
