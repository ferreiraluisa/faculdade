#include "Acao.h"

Acao::Acao(){}

Acao::Acao(string ticker, int quantidade){
    cotacoes = new Preco[500000];
    dividendos = new Dividendo[500000];
    splits = new Split[500000];
    _ticker = ticker;
    _quantidade = quantidade;
}

Acao::~Acao(){
    delete []cotacoes;
    delete []dividendos;
    delete []splits;
}
/*testei e esta funcionando !!!(anotei isso na primeira vez que eu tinha testado, implementei assim na main:
int main(int argc, char **argv){
    classeBase controle(argv[1],argv[2],argv[3],argv[4]);
    controle.lerArquivos();
    controle.ordenaArquivos();
    Acao acao("B3SA3",0);
    acao.armazenandoDados(controle.getArrayPreco(),controle.getSizePreco(), controle.getArrayDividendo(), controle.getSizeDividendo(), controle.getArraySplit(),controle.getSizeSplit());
    acao.imprime();
}
assim mostrou que tinha armazenado os dados na objeto acao direitinho, mas na hora de implementar no preco o programa "crashava"
)
void Acao::armazenandoDados(Preco *preco, int n, Dividendo *dividendo, int o, Split *split, int p){
    int a = 0;
    int b=0;
    int c=0;
    for(int i=0;i<n;i++){
        if(preco[i].getTicker() == _ticker){
            cotacoes[a] = Preco(preco[i].getTicker(), preco[i].getData(), preco[i].getPreco());
            a++;
        }
    }
    for(int i=0;i<o;i++){
        if(dividendo[i].getTicker() == _ticker){
            dividendos[b] = Dividendo(dividendo[i].getTicker(), dividendo[i].getData(),dividendo[i].getValorDividendo());
            b++;
        }
    }
    for(int i=0;i<p;i++){
        if(split[i].getTicker() == _ticker){
            splits[c] = Split(split[i].getTicker(), split[i].getData(), split[i].getSplit());
            c++;
        }
    }
    sizeCotacoes = a;
    sizeDividendos = b;
    sizeSplits = c;
}
*/
string Acao::getTicker(){
    return this->_ticker;
}
/*
Essa foi a forma que eu pensei para conseguir pegar o ultimo dia do mes e pelos meus teste estava dando certo! Eu faria uma data inteira que seria a data minima, ou seja, a data com dia igual a 01 e depois transfomaria o dado data que era string em inteiro para achar o ultimo numero maior que a dataMinima, esse seria o ultimo dia do mes!
int Acao::dataToInt(string data){
    data.erase(data.begin()+4);
    data.erase(data.begin()+6);

    return stoi(data);
}
int Acao::dataMinima(string data){
    for(int j=0;j<data.size();j++) 
        if(data[j] == '-') data[j] = ' ';
        stringstream ss;
        ss << data;
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
//Complexidade O(n)
string Acao::ultimoDiaUtil(string data){
    int maiorData = -1;
    for(int i=0;i<sizeCotacoes;i++){
        int dataInteiro = dataToInt(cotacoes[i].getData());
        //cout<<dataInteiro<<" "<<dataMaxima(data)<<endl;
        if(dataInteiro>dataMinima(data)){
            if(dataInteiro > maiorData)
                maiorData = dataInteiro;
        }
    }
    return to_string(maiorData);
}
*/

/*void Acao::imprimeTeste(){
    for(int i=0;i<sizeCotacoes;i++){
        std::cout<<cotacoes[i].getData()<<" "<<cotacoes[i].getPreco()<<endl;
    }
    cout<<"------------------------"<<endl;
    for(int i=0;i<sizeDividendos;i++){
        cout<<dividendos[i].getData()<<" "<<dividendos[i].getValorDividendo()<<endl;
    }
    cout<<"-------------------------"<<endl;
    for(int i=0;i<sizeSplits;i++){
        cout<<splits[i].getData()<<" "<<splits[i].getSplit()<<endl;
    }

}*/
