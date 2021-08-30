#ifndef CLASSE_BASE_H
#define CLASSE_BASE_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include "CarteiraInvestidor.h"
#include "preco.h"
#include "dividendo.h"
#include "split.h"
#include "operacoes.h"

//essa é a classe controle, que tem tudo que eu fiz armazenado

//functors 
//usei functors para auxiliar na ordenacao

class ComparaPrecosTicket {
public:
    bool operator() (Preco &acaopreco, Preco &acaopreco2) const {
        return acaopreco.getTicker() < acaopreco2.getTicker();
    }
};
class ComparaPrecosData {
public:
    bool operator() (Preco &acaopreco, Preco &acaopreco2) const {
        return acaopreco.getData() > acaopreco2.getData();
    }
};
class ComparaDividendoTicket {
public:
    bool operator() (Dividendo &acaodividendo, Dividendo &acaodividendo2) const {
        return acaodividendo.getTicker() < acaodividendo2.getTicker();
    }
};
class ComparaDividendoData {
public:
    bool operator() (Dividendo &acaodividendo, Dividendo &acaodividendo2) const {
        return acaodividendo.getData() > acaodividendo2.getData();
    }
};
class ComparaSplitTicket {
public:
    bool operator() (Split &acaosplit, Split &acaosplit2) const {
        return acaosplit.getTicker() < acaosplit2.getTicker();
    }
};
class ComparaSplitData {
public:
    bool operator() (Split &acaosplit, Split &acaosplit2) const {
        return acaosplit.getData() > acaosplit2.getData();
    }
};
class ComparaOperacoesTicket {
public:
    bool operator() (Operacoes &operacoesbolsa, Operacoes &operacoesbolsa2) const {
        return operacoesbolsa.getTicker() < operacoesbolsa2.getTicker();
    }
};
class ComparaOperacoesData {
public:
    bool operator() (Operacoes &operacoes, Operacoes &operacoes2) const {
        return operacoes.getData() > operacoes2.getData();
    }
};


class classeBase{
    private:
        string _arquivoPreco;
        string _arquivoDividendos;
        string _arquivoSplit;
        string _arquivoOperacoes;
        int sizePreco;
        int sizeDividendo;
        int sizeSplit;
        int sizeOperacoes;
        Preco *precoAcoes;
        Dividendo *dividendoAcoes;
        Split *splitAcoes;
        Operacoes *operacoesBolsa;
        Acao *acoesAux;
        char auxOperacaoPrincipal;
        CarteiraInvestidor investidor;
    public:
        //construtor
        classeBase();
        classeBase(string arquivoPreco,std::string arquivoDividendos,std::string arquivoSplit,std::string arquivoOperacoes);
        //destrutor
        ~classeBase();
        //casting
        int dataInt(std::string data);
        int valorInt(std::string preco);
        //ler arquivos
        void lerPreco();
        void lerDividendos();
        void lerSplits();
        void lerOperacoes();
        void lerArquivos();
        //ordenacao
        //escolhi usar o MergeSort porque precisava de um metodo de ordenacao estavel, teria 3 opcoes a partir dai: InsertionSort, BubbleSort e MergeSort. Mas o MergeSort e mais eficiente com tamanhos de entrada grande, por isso escolhi o mergesort.
        template <class T,class T1> void merge(T *v, int p, int q, int r, T1 compara, T *aux);
        template <class T, class T1> void mergeSort(T *v, int p,int r,T1 compara, T *aux);
        void ordenaPreco(Preco *v, int n);
        void ordenaDividendo(Dividendo *v, int n);
        void ordenaSplit(Split *v, int n);
        void ordenaOperacoes(Operacoes *v, int n);
        void ordenaArquivos();
        //funcoes de saida
        int consulta(int i);
        void leAcoes();
        //bool acaoRepetida(string ticker, int n);
        //void simulaBolsa();
        //void saidaD();
        //busca binaria
        int BuscaBin(Preco *array,int begin, int end, std::string chaveTickerData); //Para Consulta Q, concatenei o ticker com a data porque minha ideia anterior era fazer uma unica busca binaria com duas chaves, so que nao deu certo por diversos motivos e essa foi a solucao que encontrei
        //getters
        Preco* getArrayPreco();
        Dividendo *getArrayDividendo();
        Split *getArraySplit();
        Operacoes *getArrayOperacoes();
        int getSizePreco();
        int getSizeDividendo();
        int getSizeSplit();
        int getSizeOperacoes();
        char getAuxOperacao(); //ve qual é a operacao principal do arquivo operacoes(me refiro a operação principal o char da primeira linha do arquivo);
        //checar eventos
        bool dividendos(string ticker, string data);
        bool split(string ticker, string data);

        //funcoes para teste
        void imprime();
        void imprime2();

};
 

//implementacoes com o template
//! necessario fazer elas no arquivo '.h' porque a funcao feita com template nao existe de fato, so passa a existir caso ela for chamada na main ou em outro lugar
//usei mergeSort porque precisava de um algoritmo estável e que lidasse bem com entradas grandes(InsertionSort e BubbleSort os dos outros algortimos estaveis famosos nao lidam bem com entradas grandes)
//ordenacao com template
template <class T,class T1>
void classeBase::merge(T *v, int p, int q, int r, T1 compara, T *aux) {
    int tam = r-p;
    int i = p; //cursor 1
    int j = q; //cursor 2
    int k = 0; //cursor para aux
    while(i < q && j < r) {
        if (compara(v[i],v[j]))
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while(i < q)
        aux[k++] = v[i++];
    while(j < r)
        aux[k++] = v[j++];
    for(k = 0; k < tam; k++)
        v[p+k] = aux[k]; 
}
template <class T, class T1>
void classeBase::mergeSort(T *v, int p, int r, T1 compara, T *aux) {
    if (p < r-1) {
        int meio = (p+r) / 2;
        mergeSort(v, p, meio,compara,aux);
        mergeSort(v, meio, r,compara,aux);
        merge(v, p, meio, r, compara, aux);
    }
}


#endif