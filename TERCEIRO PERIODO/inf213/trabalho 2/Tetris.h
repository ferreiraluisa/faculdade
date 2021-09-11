#ifndef TETRIS_H
#define TETRIS_H

class Tetris{
    private:
        int numColums;
        int *alturas;
        char **jogo;
        char ***pecas;
        void destroy();
        void create();
        void createPecas();
        void inicializaPeca(char id, const char peca0[4][4], const char peca90[4][4], const char peca180[4][4], const char peca270[4][4]);
        int getNumberIdPeca(char id);
        int alturaMaxima();
        void resizeGameRowCapacity();
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
        //funcoes para teste
        void imprime();
};

#endif
