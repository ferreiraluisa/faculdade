#ifndef INF112_POSICOESVETOR_H
#define INF112_POSICOESVETOR_H

#include <stdexcept>

class PosicoesVetor{
    public:
        int _n;
        int *_vetor = new int;
        PosicoesVetor(int n);
        ~PosicoesVetor();
        void le_posicoes();
        int excecao_n();
        int excecao_nao_numero(int n);
        int excecao_inexistente(int n);
};

#endif