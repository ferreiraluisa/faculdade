#ifndef INF112_EXCECA0SOMA_H
#define INF112_EXCECA0SOMA_H
#include "excecaoacimax.h"
class Excecao {
    public:
        int _x;
        int _n;
        int *_numeros = new int;
        int _soma;
        int _vezes;
        int _media;
        Excecao(int n);
        ~Excecao();
        int excecaosomax(int soma);
        int excecaoX(int x);
        int excecao_numeros(int n);
        int excecaoacimadeX() throw(ExcecaoAcimaX);
        void le_numeros();
};

#endif