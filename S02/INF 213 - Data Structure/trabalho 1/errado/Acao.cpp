#include "Acao.h"

Acao::Acao(){}

Acao::Acao(string ticker,int quantidade, int n){
    _quantidade = quantidade;
    _ticker = ticker;
    dividendos = new Dividendo[n];
    precos = new Preco[n];
    splits = new Split[n];
}

Acao::~Acao(){
    delete []dividendos;
    delete []precos;
    delete []splits;
}

void Acao::armazenandoDadosPreco(Preco *preco, int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(preco[i].getTicker() == _ticker){
            Preco aux(_ticker,preco[i].getData(),preco[i].getPreco());
            precos[j] = aux;
            j++;
        }
        
    }
    this->sizePrecos = j;
}
void Acao::armazenandoDadosDividendos(Dividendo *dividendo, int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(dividendo[i].getTicker() == _ticker){
            Dividendo aux(_ticker,dividendo[i].getData(),dividendo[i].getValorDividendo());
            dividendo[j] = aux;
            j++;
        }
        
    }
    this->sizeDividendos = j;
}
void Acao::armazenandoDadosSplits(Split *split, int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(split[i].getTicker() == _ticker){
            Split aux(_ticker,split[i].getData(),split[i].getSplit());
            split[j] = aux;
            j++;
        }
        
    }
    this->sizeDividendos = j;
}
void Acao::imprime(){
    for(int i=0;i<sizePrecos;i++){
        cout<<precos[i].getData()<<" "<<precos[i].getTicker()<<"\n";
    }
}

/*void Acao::splitData(int i){
    for(int j=0;j<precos[i].getData().size();j++) 
        if(precos[i].getData()[j] == '-') precos[i].getData()[j] == ' ';
    stringstream ss;
    ss <<precos[i].getData();
    ss >> dia >> mes>> ano;
}*/

int Acao::dataMinima(string data){
    for(int j=0;j<data.size();j++) 
        if(data[j] == '-') data[j] = ' ';
        stringstream ss;
        ss <<data;
        int dia;
        int mes;
        int ano;
        ss >> ano >> mes>> dia;
        string mes_;
        if(mes<10) mes_ = "0" + to_string(mes);
        else mes_ = to_string(mes);

        string ano_ = to_string(ano);
        string datamaxima = ano_ + mes_ + "01";
        return stoi(datamaxima);
}
int Acao::dataToInt(string data){
    data.erase(data.begin()+4);
    data.erase(data.begin()+6);

    return stoi(data);
}
//Complexidade O(n)
string Acao::ultimoDiaUtil(string data){
    int maiorData = -1;
    for(int i=0;i<sizePrecos;i++){
        int dataInteiro = dataToInt(precos[i].getData());
        //cout<<dataInteiro<<" "<<dataMaxima(data)<<endl;
        if(dataInteiro>dataMinima(data)){
            if(dataInteiro > maiorData)
                maiorData = dataInteiro;
        }
    }
    return to_string(maiorData);
}

string Acao::getTicker(){
    return this->_ticker;
}

void Acao::setQuantidade(int quantidade){
    this->_quantidade = quantidade;
}

Preco * Acao::getPrecoAcao(){
    return this->precos;
}
Dividendo * Acao::getDividendoAcao(){
    return this->dividendos;
}
Split * Acao::getSplitAcao(){
    return this->splits;
}