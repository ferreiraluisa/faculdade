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
}

//Casting

//transformei a data para inteiro, porque é mais "barato" comparar inteiros do que strings na hora de fazer a ordenação
int classeBase::dataInt(std::string data){
    data.erase(data.begin()+4);
    data.erase(data.begin()+6);

    return stoi(data);

}

int classeBase::valorInt(std::string  _preco){
    double aux = atof(_preco.c_str());
    aux = int((100 * aux) + 0.000001);
    return aux;

}

//Ler arquivos
//funcao responsavel por ler e armazenar os dados no arquivo que contem o preco das acoes, e isso sera armazenado num array de Preco(polimorfismo)
/*void classeBase::lerPreco(){ 
    int i=0;
    std::ifstream file(this->_arquivoPreco);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty) {
        std::string ticker;
    
        std::string data;
    
        std::string preco;
    
        std::string lixo;
        while(file.good()){
       
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
}*/
void classeBase::lerPreco(){
    int i=0;
    std::ifstream file(this->_arquivoPreco);
    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss;
        for(int i=0;i<line.size();i++)
            if(line[i] == ',') line[i] = ' ';
        std::string ticker;
        std::string data;
        std::string lixo[5];
        std::string preco;
        
        ss<<line;

        ss>>ticker>>data>>lixo[0]>>lixo[1]>>lixo[2]>>preco>>lixo[3]>>lixo[4];

        Preco aux(ticker,dataInt(data),valorInt(preco));
        precoAcoes[i] = aux;
        i++;
    }
    this->sizePreco = i;
}
//funcao responsavel por ler e armazenar os dados no arquivo que contem os dividendos das acoes,se tiver, isso sera armazenado num array de Dividendos(polimorfismo)
void classeBase::lerDividendos(){
    int i=0;
    std::ifstream file(this->_arquivoDividendos);
    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss;
        for(int i=0;i<line.size();i++)
            if(line[i] == ',') line[i] = ' ';
        std::string ticker;
        std::string data;
        std::string preco;
        
        ss<<line;

        ss>>ticker>>data>>preco;

        Dividendo aux(ticker,dataInt(data),valorInt(preco));
        dividendoAcoes[i] = aux;
        i++;
    }
    this->sizeDividendo = i;
}
/*void classeBase::lerDividendos(){ 
    int i=0;
    std::ifstream file(this->_arquivoDividendos);
    
    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty){
        std::string ticker;
    
        std::string data;
    
        std::string dividendo;
        while(file.good()){
       
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
*/
//funcao responsavel por ler e armazenar os dados no arquivo que contem as splits das acoes,se ocorrer, isso sera armazenado num array de Splits(polimorfismo)
void classeBase::lerSplits(){
    int i=0;
    std::ifstream file(this->_arquivoSplit);
    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss;
        for(int i=0;i<line.size();i++)
            if(line[i] == ',') line[i] = ' ';
        std::string ticker;
        std::string data;
        std::string split;
        
        ss<<line;

        ss>>ticker>>data>>split;

        Split aux(ticker,dataInt(data),split);
        splitAcoes[i] = aux;
        i++;
    }
    this->sizeSplit = i;
}
/*void classeBase::lerSplits(){ 
    int i=0;
    std::ifstream file(this->_arquivoSplit);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty){
        std::string ticker;
    
        std::string data;
    
        std::string split;
        while(file.good()){
       
        std::getline(file,ticker,',');
        std::getline(file,data,',');
        std::getline(file,split,'\n');
        Split aux(ticker,dataInt(data),split);
        splitAcoes[i] = aux;
        i++;
     }
    this->sizeSplit = i;
    }
}*/
//funcao responsavel por ler e armazenar os dados no arquivo que contem as operacoes da bolsa,se ocorrer, isso sera armazenado num array de Operacoes(polimorfismo)
void classeBase::lerOperacoes(){
    int i=0;
    std::ifstream file(this->_arquivoOperacoes);
    std::string line;
    while(std::getline(file,line)){
        if(i==0){
            std::stringstream ss;
            ss <<line;
            char operacaop;

            ss >> operacaop;
            auxOperacaoPrincipal = operacaop;
            i++;
        }
        else{
            if(auxOperacaoPrincipal=='Q'){
                std::stringstream ss;
                for(int i=0;i<line.size();i++)
                    if(line[i] == ',') line[i] = ' ';
                std::string data;
                char operacaosecundaria;
                std::string ticker;
        
                ss<<line;

                ss>>data>>operacaosecundaria>>ticker;

                Operacoes aux(ticker,dataInt(data),auxOperacaoPrincipal,operacaosecundaria,0);
                operacoesBolsa[i-1] = aux;
                i++;

            }
            else{
                std::stringstream ss;
                for(int i=0;i<line.size();i++)
                    if(line[i] == ',') line[i] = ' ';
                std::string data;
                char operacaosecundaria;
                std::string ticker;
                int quantidade;
        
                ss<<line;

                ss>>data>>operacaosecundaria>>ticker>>quantidade;

                Operacoes aux(ticker,dataInt(data),auxOperacaoPrincipal,operacaosecundaria,quantidade);
                operacoesBolsa[i-1] = aux;
                i++;
            }
        }
    }
    this->sizeOperacoes = i-1;
}
/* tinha feito assim mas deu erro de memoria no submitty, deixei aqui para ver depois
void classeBase::lerOperacoes(){ 
    int i=0;
    std::ifstream file(this->_arquivoOperacoes);

    bool isEmpty = (file.peek() == EOF); 
    if(!isEmpty) {
            std::string ticker;
        
            std::string data;
        
            std::string operacaoPrincipal;

            std::string operacaoSecundaria;
            
            std::string quantidade;
        while(file.good()){

            if (i == 0){ //essa vai ser a primeira linha
                std::getline(file, operacaoPrincipal, '\n');
                this->auxOperacaoPrincipal = operacaoPrincipal;
                i++;
            }
            else{
                if (this->auxOperacaoPrincipal == "Q"){
                    std::getline(file, data, ',');
                    std::getline(file, operacaoSecundaria, ',');
                    std::getline(file, ticker, '\n');
                    Operacoes aux(ticker, dataInt(data), operacaoPrincipal, operacaoSecundaria, 0);
                    operacoesBolsa[i - 1] = aux;
                    i++;
                }
                else{
                    std::getline(file, data, ',');
                    std::getline(file, operacaoSecundaria, ',');
                    std::getline(file, ticker, ',');
                    std::getline(file, quantidade, '\n');
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
void classeBase::ordenaArquivos(){
    ordenaPreco(precoAcoes, sizePreco);
    ordenaDividendo(dividendoAcoes, sizeDividendo);
    ordenaSplit(splitAcoes, sizeSplit);
}

//busca binaria

int classeBase::BuscaBin(Preco *array,int begin, int end,std::string chaveTickerData) {
    if (begin > end) return end;
    int meio = (end-begin)/2 + begin;
    std::string aux = (array[meio].getTicker()) + (std::to_string(array[meio].getData()));
    if(aux == chaveTickerData) return meio;
    if(aux > chaveTickerData) return BuscaBin(array,begin,meio-1,chaveTickerData);
    return BuscaBin(array,meio+1, end,chaveTickerData);
}

//funcao de saida
int classeBase::consulta(int i){
    std::string TickerData = operacoesBolsa[i].getTicker() + std::to_string(operacoesBolsa[i].getData());
    int pos = BuscaBin(precoAcoes,0,sizePreco-1,TickerData);
    return precoAcoes[pos].getPreco();
}

//funcoes para teste!
void classeBase::imprime(){
    for(int i=0;i<sizePreco;i++){
        std::cout<<"---------------------"<<std::endl;
        std::cout<<this->precoAcoes[i].getTicker()<<std::endl;
        std::cout<<this->precoAcoes[i].getData()<<std::endl;
        std::cout<<this->precoAcoes[i].getPreco()<<std::endl;
    }
}
void classeBase::imprime2(){
    for(int i=0;i<sizeOperacoes;i++){
        std::cout<<"--------------"<<i<<"--------------"<<std::endl;
        std::cout<<this->operacoesBolsa[i].getTicker()<<std::endl;
        std::cout<<this->operacoesBolsa[i].getData()<<std::endl;
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