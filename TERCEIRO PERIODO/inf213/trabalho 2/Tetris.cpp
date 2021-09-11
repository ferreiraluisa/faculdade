#include "Tetris.h"


//construtores
Tetris::Tetris(int _numcolums){
    numColums = _numcolums;
}
Tetris::~Tetris(){
}
void Tetris::create(){
    jogo = new char *[numColums];
}
void Tetris::destroy(){
    delete[] jogo;
}

//funções auxiliares(privadas)
int Tetris::alturaMaxima(){
    int maior = 0;
    for(int i=0;i<numColums;i++){
        if(alturas[i] > maior) maior = alturas[i];
    }

    return maior;
}

//funcoes publicas, ditas na especificação
char Tetris::get(int colums, int lines){ //retorna um caractere que representa o estado de tal pixel no jogo atual
    return jogo[colums][lines];
}
void Tetris::removeColuna(int coluna){ //remove a coluna do jogo (diminuindo, assim, sua largura)

}
void Tetris::removeLinhasCompletas(){ //remove todos os pixels do jogo que estiverem em linhas completas

}
int Tetris::getNumColum(){ //retorna o número de colunas (largura) do jogo Tetris. Esse número deverá ser igual ao valor passado pelo construtor do jogo
    return numColums;
}
int Tetris::getAltura(int colum){ //retorna a altura da coluna c do jogo
    return alturas[colum];
}
int Tetris::getAltura(){ //retorna a altura maxima do jogo atual
    return alturaMaxima();
}
bool Tetris::adicionaForma(int coluna, int linha, char id, int rotacao){ //retorna se é possível ou não adicionar a peça

}