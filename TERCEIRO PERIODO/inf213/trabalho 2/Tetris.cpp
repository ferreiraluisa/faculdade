#include "Tetris.h"
#include <iostream>
using namespace std;


//construtores
Tetris::Tetris(int _numcolums){
    numColums = _numcolums;
    create();

}
Tetris::~Tetris(){
    destroy();
}
void Tetris::create(){
    jogo = new char *[numColums];
    pecas = new char **[28];
    for(int i = 0;i<28;i++){
        pecas[i] = new char*[4];
        for(int j=0;j<4;j++){
            pecas[i][j] = new char[4];
        }
    }
    createPecas();
}
void Tetris::destroy(){
    delete[] jogo;
    for(int i = 0;i<28;i++){
        for(int j=0;j<4;j++){
            delete[] pecas[i][j];
        }
        delete[] pecas[i];
    }
    delete[] pecas;
}

//funções auxiliares(privadas)
int Tetris::alturaMaxima(){
    int maior = 0;
    for(int i=0;i<numColums;i++){
        if(alturas[i] > maior) maior = alturas[i];
    }

    return maior;
}

int Tetris::getNumberIdPeca(char id){
    switch (id)
    {
    case 'I':
        return 0;
    case 'J':
        return 4;
    case 'L':
        return 8;
    case 'O':
        return 12;
    case 'S':
        return 16;
    case 'T':
        return 20;
    case 'Z':
        return 24;
    
    default:
        return 0;
    }
}

void Tetris::inicializaPeca(char id, const char peca0[4][4], const char peca90[4][4], const char peca180[4][4], const char peca270[4][4]){\
    int pecaId = getNumberIdPeca(id);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            pecas[pecaId][i][j] = peca0[i][j];    
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            pecas[pecaId+1][i][j] = peca90[i][j];    
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            pecas[pecaId+2][i][j] = peca180[i][j];    
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            pecas[pecaId+3][i][j] = peca270[i][j];    
        }
    }
}

void Tetris::createPecas(){
    char pecaI_0_180[4][4] {
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
    };
    char pecaI_90_270[4][4] {
        {'I','I','I','I'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('I',pecaI_0_180,pecaI_90_270,pecaI_0_180,pecaI_90_270);
    char pecaJ_0[4][4] {
        {'J','J','J','J'},
        {' ',' ',' ','J'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaJ_90[4][4] {
        {' ','J',' ',' ',},
        {' ','J',' ',' '},
        {' ','J',' ',' '},
        {'J','J',' ',' '},
    };
    char pecaJ_180[4][4] {
        {'J',' ',' ',' '},
        {'J','J','J','J'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaJ_270[4][4] {
        {'J','J',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
    };
    inicializaPeca('J',pecaJ_0,pecaJ_90,pecaJ_180,pecaJ_270);
    char pecaL_0[4][4] {
        {'L','L','L','L'},
        {'L',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaL_90[4][4] {
        {'L','L',' ',' '},
        {' ','L',' ',' '},
        {' ','L',' ',' '},
        {' ','L',' ',' '},
    };
    char pecaL_180[4][4] {
        {' ',' ',' ','L'},
        {'L','L','L','L'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaL_270[4][4] {
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L','L',' ',' '},
    };
    inicializaPeca('L',pecaL_0,pecaL_90,pecaL_180,pecaL_270);
    char pecaO_0_90_180_270[4][4] {
        {'O','O',' ',' '},
        {'O','O',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('O',pecaO_0_90_180_270,pecaO_0_90_180_270,pecaO_0_90_180_270,pecaO_0_90_180_270);
    char pecaS_0_180[4][4] {
        {' ','S','S',' '},
        {'S','S',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaS_90_270[4][4] {
        {'S',' ',' ',' '},
        {'S','S',' ',' '},
        {' ','S',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('S',pecaS_0_180,pecaS_90_270,pecaS_0_180,pecaS_90_270);
    char pecaT_0[4][4] {
        {'T','T','T',' '},
        {' ','T',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaT_90[4][4] {
        {' ','T',' ',' '},
        {'T','T',' ',' '},
        {' ','T',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaT_180[4][4] {
        {' ','T',' ',' '},
        {'T','T','T',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaT_270[4][4] {
        {'T',' ',' ',' '},
        {'T','T',' ',' '},
        {'T',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('T',pecaT_0,pecaT_90,pecaT_180,pecaT_270);
    char pecaZ_0_180[4][4] {
        {'Z','Z',' ',' '},
        {' ','Z','Z',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char pecaZ_90_270[4][4] {
        {' ','Z',' ',' '},
        {'Z','Z',' ',' '},
        {'Z',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('Z',pecaZ_0_180,pecaZ_90_270,pecaZ_0_180,pecaZ_90_270);
    
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
    return true;
}

//funcoes para teste
void Tetris::imprime(){
    char inicio = 'I';
    cout<<"-------------PECA"<<inicio++<<"-------------"<<endl;
    for(int i=0;i<28;i++){
        if(i%4==0)cout<<"-------------PECA"<<inicio++<<"-------------"<<endl;
       for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                cout<<pecas[i][j][k]<<" ";
            }
            cout<<endl;
       }    
    }
    
}