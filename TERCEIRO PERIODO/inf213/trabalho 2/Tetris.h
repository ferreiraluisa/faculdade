#ifndef TETRIS_H
#define TETRIS_H

class Tetris{
    private:
        int numColums;
        int *alturas;
        char **jogo;
        char **pecaAtual;
        void destroy();
        void create();
        int alturaMaxima();
        void createPecaAtual();
        void resizeGameRowCapacity();
        void getPeca(char _id, char &pecaAtual);
    public:
        Tetris(int _numColums);
        ~Tetris();
        char get(int colums, int lines); //retorna um caractere que representa o estado de tal pixel no jogo atual
        void removeColuna(int coluna); //remove a coluna do jogo (diminuindo, assim, sua largura)
        void removeLinhasCompletas(); //remove todos os pixels do jogo que estiverem em linhas completas
        int getNumColum(); //retorna o número de colunas (largura) do jogo Tetris. Esse número deverá ser igual ao valor passado pelo construtor do jogo
        int getAltura(int colum); //retorna a altura da coluna c do jogo
        int getAltura(); ////retorna a altura maxima do jogo atual
        bool adicionaForma(int coluna, int linha, char id, int rotacao); //retorna se é possível ou não adicionar a peça
};

#endif
