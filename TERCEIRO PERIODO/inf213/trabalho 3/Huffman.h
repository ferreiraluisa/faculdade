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
		HuffmanNode(const char &elem_, const int &freq_){
            elem = elem_;
            freq = freq_;
            codigo = "";
            left = NULL;
            right = NULL;
        }
		char elem;
        int freq;
        string codigo;
        HuffmanNode *left, *right;
        bool isLeaf(){
            return this->left == NULL && this->right == NULL;
        }
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
        // HuffManTree & operator=(const HuffManTree &);
        //destrutor
        ~HuffManTree();


        void comprimir(MyVec<bool> &out, const MyVec<char> &in);
        void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;

        //funcoes para teste
        void imprimeBFS() const;
        MyMap<char, string> tabelaCodigo;

    private:
        HuffmanNode *root;
        MyPriorityQueue<pair<int,HuffmanNode*>> pq; 
        //funcoes auxiliares
        void create();
        void destroy(HuffmanNode *node);
        void geraMap(HuffmanNode *rootNode);
        //funcoes teste
        void imprimeFila();
};

#endif