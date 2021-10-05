#ifndef HuffManTree_H
#define HuffManTree_H
#include "MyVec.h"
class HuffManTree{
    public:
        //construtor
        HuffManTree(int freqs[256]);
        //construtor de cópia
        HuffManTree(const HuffManTree &other);
        //operador de cópia
        HuffManTree & operator=(const HuffManTree &);
        //destrutor
        ~HuffManTree();

        void comprimir(MyVec<bool> &out, const MyVec<char> &in);
        void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;

    private:

};

#endif