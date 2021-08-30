#include "classeBase.h"
#include <cstring>
#include <sstream>

//construtor
classeBase::classeBase(string arquivoPreco,string arquivoDividendos,string arquivoSplit,string arquivoOperacoes){
    _arquivoPreco = arquivoPreco;
    _arquivoDividendos = arquivoDividendos;
    _arquivoSplit = arquivoSplit;
    _arquivoOperacoes = arquivoOperacoes;

    precoAcoes = new Preco[500000];
    dividendoAcoes = new Dividendo[500000];
    splitAcoes = new Split[500000];
    operacoesBolsa = new Operacoes[500000];
    acoesAux = new Acao[500000];

    sizePreco = 0;
    sizeDividendo = 0;
    sizeSplit = 0;
    sizeOperacoes = 0;

}

//destrutor
classeBase::~classeBase(){
    delete []precoAcoes;
    delete []dividendoAcoes;
    delete []splitAcoes;
    delete []operacoesBolsa;
    delete []acoesAux;
}

//Casting
int classeBase::valorInt(string  _preco){
    double aux = atof(_preco.c_str());
    aux = int((100 * aux) + 0.000001);
    return aux;

}

//Ler arquivos, todas essas funcoes tem complexidade O(n)
//funcao responsavel por ler e armazenar os dados no arquivo que contem o preco das acoes, e isso sera armazenado num array de Preco
void classeBase::lerPreco(){
    int i=0;
    ifstream file(this->_arquivoPreco);
    string line;
    while(getline(file,line)){
        stringstream ss;
        for(int i=0;i<line.size();i++)
            if(line[i] == ',') line[i] = ' ';
        string ticker;
        string data;
        string lixo[5];
        string preco;
        
        ss<<line;

        ss>>ticker>>data>>lixo[0]>>lixo[1]>>lixo[2]>>preco>>lixo[3]>>lixo[4];

        Preco aux(ticker,data,valorInt(preco));
        precoAcoes[i] = aux;
        i++;
    }
    this->sizePreco = i;
}
//funcao responsavel por ler e armazenar os dados no arquivo que contem os dividendos das acoes,se tiver, isso sera armazenado num array de Dividendos
void classeBase::lerDividendos(){
    int i=0;
    ifstream file(this->_arquivoDividendos);
    string line;
    while(getline(file,line)){
        stringstream ss;
        for(int i=0;i<line.size();i++)
            if(line[i] == ',') line[i] = ' ';
        string ticker;
        string data;
        string preco;
        
        ss<<line;

        ss>>ticker>>data>>preco;

        Dividendo aux(ticker,data,valorInt(preco));
        dividendoAcoes[i] = aux;
        i++;
    }
    this->sizeDividendo = i;
}
//funcao responsavel por ler e armazenar os dados no arquivo que contem as splits das acoes,se ocorrer, isso sera armazenado num array de Splits
void classeBase::lerSplits(){
    int i=0;
    ifstream file(this->_arquivoSplit);
    string line;
    while(getline(file,line)){
        stringstream ss;
        for(int i=0;i<line.size();i++)
            if(line[i] == ',') line[i] = ' ';
        string ticker;
        string data;
        string split;
        
        ss<<line;

        ss>>ticker>>data>>split;

        Split aux(ticker,data,split);
        splitAcoes[i] = aux;
        i++;
    }
    this->sizeSplit = i;
}
//funcao responsavel por ler e armazenar os dados no arquivo que contem as operacoes da bolsa,se ocorrer, isso sera armazenado num array de Operacoes
void classeBase::lerOperacoes(){
    int i=0;
    ifstream file(this->_arquivoOperacoes);
    string line;
    while(getline(file,line)){
        if(i==0){
            stringstream ss;
            ss <<line;
            char operacaop;

            ss >> operacaop;
            auxOperacaoPrincipal = operacaop;
            i++;
        }
        else{
            if(auxOperacaoPrincipal=='Q'){
                stringstream ss;
                for(int i=0;i<line.size();i++)
                    if(line[i] == ',') line[i] = ' ';
                string data;
                char operacaosecundaria;
                string ticker;
        
                ss<<line;

                ss>>data>>operacaosecundaria>>ticker;

                Operacoes aux(ticker,data,auxOperacaoPrincipal,operacaosecundaria,0);
                operacoesBolsa[i-1] = aux;
                i++;

            }
            else{
                stringstream ss;
                for(int i=0;i<line.size();i++)
                    if(line[i] == ',') line[i] = ' ';
                string data;
                char operacaosecundaria;
                string ticker;
                int quantidade;
        
                ss<<line;

                ss>>data>>operacaosecundaria>>ticker>>quantidade;

                Operacoes aux(ticker,data,auxOperacaoPrincipal,operacaosecundaria,quantidade);
                operacoesBolsa[i-1] = aux;
                i++;
            }
        }
    }
    this->sizeOperacoes = i-1;
}
/*tinha feito o parsing assim, mas deu erro no submitty por memoria invalida fiquei travada um dia inteiro tentando achar o erro mas nao consegui ai fiz do jeito que voce mostrou para gente(tinha olhado no youtube e assim que eu me lembrava de ter feito em programacao2(inf112)), deixei aqui pra tentar ver se descubro o erro depois caso eu lembre/sobre tempo
void classeBase::lerPreco(){ 
    int i=0;
    ifstream file(this->_arquivoPreco);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty) {
        string ticker;
    
        string data;
    
        string preco;
    
        string lixo;
        while(file.good()){
       
        getline(file,ticker,',');
        getline(file,data,',');
        getline(file,lixo,',');
        getline(file,lixo,',');
        getline(file,lixo,',');
        getline(file,preco,',');
        getline(file,lixo,',');
        getline(file,lixo,'\n');
        Preco aux(ticker,dataInt(data),valorInt(preco));
        precoAcoes[i] = aux;
        i++;
    }
    this->sizePreco = i;
    }
}
void classeBase::lerDividendos(){ 
    int i=0;
    ifstream file(this->_arquivoDividendos);
    
    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty){
        string ticker;
    
        string data;
    
        string dividendo;
        while(file.good()){
       
        getline(file,ticker,',');
        getline(file,data,',');
        getline(file,dividendo,'\n');
        Dividendo aux(ticker,dataInt(data),valorInt(dividendo));
        dividendoAcoes[i] = aux;
        i++;
     }
    this->sizeDividendo = i;
    }
}
void classeBase::lerSplits(){ 
    int i=0;
    ifstream file(this->_arquivoSplit);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty){
        string ticker;
    
        string data;
    
        string split;
        while(file.good()){
       
        getline(file,ticker,',');
        getline(file,data,',');
        getline(file,split,'\n');
        Split aux(ticker,dataInt(data),split);
        splitAcoes[i] = aux;
        i++;
     }
    this->sizeSplit = i;
    }
}
 tinha feito assim mas deu erro de memoria no submitty, deixei aqui para ver depois
void classeBase::lerOperacoes(){ 
    int i=0;
    ifstream file(this->_arquivoOperacoes);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty) {
            string ticker;
        
            string data;
        
            string operacaoPrincipal;

            string operacaoSecundaria;
            
            string quantidade;
        while(file.good()){

            if (i == 0){ //essa vai ser a primeira linha
                getline(file, operacaoPrincipal, '\n');
                this->auxOperacaoPrincipal = operacaoPrincipal;
                i++;
            }
            else{
                if (this->auxOperacaoPrincipal == "Q"){
                    getline(file, data, ',');
                    getline(file, operacaoSecundaria, ',');
                    getline(file, ticker, '\n');
                    Operacoes aux(ticker, dataInt(data), operacaoPrincipal, operacaoSecundaria, 0);
                    operacoesBolsa[i - 1] = aux;
                    i++;
                }
                else{
                    getline(file, data, ',');
                    getline(file, operacaoSecundaria, ',');
                    getline(file, ticker, ',');
                    getline(file, quantidade, '\n');
                    int quantidadeaux = 0;
                    Operacoes aux(ticker, dataInt(data), operacaoPrincipal, operacaoSecundaria, 0);
                    operacoesBolsa[i - 1] = aux;
                    i++;
                }
            }
            
        }
        this->sizeOperacoes = i-1;
    }
}*/
    

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
}

//busca binaria
//concatenei ticker e data(dois strings) para ser uma unica chave(expliquei no arquivo.h melhor)
int classeBase::BuscaBin(Preco *array,int begin, int end,string chaveTickerData) {
    if (begin > end) return end;
    int meio = (end-begin)/2 + begin;
    string aux = (array[meio].getTicker()) + (array[meio].getData());
    if(aux == chaveTickerData) return meio;
    if(aux > chaveTickerData) return BuscaBin(array,begin,meio-1,chaveTickerData);
    return BuscaBin(array,meio+1, end,chaveTickerData);
}

//funcao de saida
int classeBase::consulta(int i){
    string TickerData = operacoesBolsa[i].getTicker() + (operacoesBolsa[i].getData());
    int pos = BuscaBin(precoAcoes,0,sizePreco-1,TickerData);
    return precoAcoes[pos].getPreco();
}

/*bool classeBase::acaoRepetida(string ticker, int n){
    //busca binaria iterativa porque eu nao sei o final ao certo
    int begin =0;
    int end = n;
    while(begin <= end) {
		int meio = (end-begin)/2 + begin;
		if (acoesAux[meio].getTicker() == ticker)
			return false;
		if (acoesAux[meio].getTicker() > ticker) 
			end =  meio-1; 
		else begin = meio+1; 
	}
	return true;
}*/


//funcoes para teste!
void classeBase::imprime(){
    for(int i=0;i<sizePreco;i++){
        cout<<"---------------------"<<endl;
        cout<<this->precoAcoes[i].getTicker()<<endl;
        cout<<this->precoAcoes[i].getData()<<endl;
        cout<<this->precoAcoes[i].getPreco()<<endl;
    }
}
void classeBase::imprime2(){
    for(int i=0;i<sizeOperacoes;i++){
        cout<<"--------------"<<i<<"--------------"<<endl;
        cout<<this->operacoesBolsa[i].getTicker()<<endl;
        cout<<this->operacoesBolsa[i].getData()<<endl;
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
int classeBase::getSizePreco(){
    return this->sizePreco;
}
int classeBase::getSizeDividendo(){
    return this->sizeDividendo;
}
int classeBase::getSizeSplit(){
    return this->sizeSplit;
}
int classeBase::getSizeOperacoes(){
    return this->sizeOperacoes;
}
char classeBase::getAuxOperacao(){
    return this->auxOperacaoPrincipal;
}