#ifndef TETRIS_H
#define TETRIS_H

class Tetris{
    private:
        int numColums;
    public:
        Tetris(int _numColums);
        char get(int colums, int lines);
        void removeColuna(int coluna);
        void removeLinhasCompletas(int linha);
        void getNumColum();
        void getAltura(int colum);
        void getAltura();
        void adicionaForma(int coluna, int linha, char id, int rotacao);
};

#endif
