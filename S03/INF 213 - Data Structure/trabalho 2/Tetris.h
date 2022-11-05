#ifndef TETRIS_H
#define TETRIS_H

class Tetris{
    private:
        int numColums;
        int *alturas;
        char **jogo;
        char ***pecas; //fiz um array de 3 dimensoes, 28 matrizes de 4x4(28 porque são 7 peças com 4 rotações cada)
        int *larguraPeca;
        int *alturaPeca;
        void destroy();
        void destroyArray2D();
        void create();
        void createPecas();
        void setMedidasPeca(int largura, int altura, int &pos);
        void inicializaAltura();
        void inicializaJogo();
        void inicializaPeca(char id, const char peca0[4][4], const char peca90[4][4], const char peca180[4][4], const char peca270[4][4]);
        void eraseAlturas(int coluna);
        int getPosIdPeca(char id); //mostra qual posicao do array esta as pecas do id especifico
        int getPosIdRotacao(char id, int rotacao); //mostra qual posicao do array esta as pecas do id especifico na rotacao especifica
        int alturaMaxima() const;
        int alturaMinima() const;
        bool linhaCompleta(int linha);
        void removePecaAltura(int pos, int c);
        void removeLinha(int linha);
        void resizeGameHeightCapacity(int c, int newcapacity);
        void inserePeca(int pos, int coluna, int linha);
    public:
        Tetris(); //construtor default
        Tetris(const Tetris &); //construtor de copia
        Tetris(int _numColums); //construtor
        ~Tetris(); // destrutor
        Tetris & operator=(const Tetris &);
        char get(int colums, int row) const; //retorna um caractere que representa o estado de tal pixel no jogo atual
        void removeColuna(int coluna); //remove a coluna do jogo (diminuindo, assim, sua largura)
        void removeLinhasCompletas(); //remove todos os pixels do jogo que estiverem em linhas completas
        int getNumColunas() const; //retorna o número de colunas (largura) do jogo Tetris. Esse número deverá ser igual ao valor passado pelo construtor do jogo
        int getAltura(int colum) const; //retorna a altura da coluna c do jogo
        int getAltura() const; ////retorna a altura maxima do jogo atual
        bool adicionaForma(int coluna, int linha, char id, int rotacao); //retorna se é possível ou não adicionar a peça
        //funcoes para teste
        void imprimePeca();
        void imprimeJogo();
        void imprimeAltura(int c);
        
};

#endif
