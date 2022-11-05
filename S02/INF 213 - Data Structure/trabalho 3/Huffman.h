#ifndef HuffManTree_H
#define HuffManTree_H
#include "MyVec.h"
#include "MyPriorityQueue.h"
#include "MyQueue.h"
#include "MyMap.h"
#include <algorithm>
#include <cstring>
#include <utility>  


class HuffmanNode {
	public:
		HuffmanNode(const unsigned char &elem_, const int &freq_){
            elem = elem_;
            freq = freq_;
            codigo = "";
            left = NULL;
            right = NULL;
        }
		unsigned char elem;
        int freq;
        string codigo; //cada nodo contem um codigo(vou explicar melhor na implementação)
        HuffmanNode *left, *right;
        bool isLeaf(){ //verifica se é folha
            return this->left == NULL && this->right == NULL;
        }
        //caso de empate se a frequência do nodo for igual
        bool operator>(const HuffmanNode &other){
            return this->elem < other.elem;
        }
        bool operator<(const HuffmanNode &other){
            return this->elem > other.elem;
        }

};

class HuffManTree{
    public:
        //construtor default
        HuffManTree();
        //construtor
        HuffManTree(int freqs[256]);
        //construtor de cópia
        HuffManTree(const HuffManTree &other);
        //operador de cópia
        HuffManTree & operator=(const HuffManTree &);
        //destrutor
        ~HuffManTree();

        //funcao que vai transformar o vetor de caracteres no vetor booleano(com o código compactado)
        void comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in);
        //funcao que vai transformar o vetor de booleano(código compactado) no vetor de caracteres representado por cada um dos códigos
        void descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const;

        //funcoes para teste
        void imprimeBFS() const;

    private:
        HuffmanNode *root; //raiz da HuffmanTree
        MyMap<unsigned char, string> tabelaCodigo; //Usei myMap para fazer uma tabela com o caracter e o código que o representa pra ficar mais fácil de imprimir, preferi o myMap por causa do find() mas vi que usar uma tabela Hashi seria uma boa escolha mas já tinha terminado o trabalho quando vimos Hash então apenas deixei a ideia como ideia
        MyPriorityQueue<pair<int,HuffmanNode*>> pq; //a priority queue que no meu caso eu mexi para que os elementos de maior prioridade fossem o de menor frequência(logo depois assisti uma aula que você falou que isso não seria muito bom porque nós temos que ficar acostumados com a pq da bbt stl, mas não tive tempo de fazer da forma que você tinha sugerido)
        //funcoes auxiliares
        void create(); //cria a HuffmanTree
        void destroy(HuffmanNode *node); //Deleta toda memória que foi alocada na HuffmanTree
        void geraMap(HuffmanNode *rootNode); //vai gerar o tabelaCodigo, rodando por toda a árvore
        //funcoes teste
        void imprimeFila();
};

#endif