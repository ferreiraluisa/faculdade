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
    char peca_I_0_180[4][4] {
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
    };
    char peca_I_90_270[4][4] {
        {'I','I','I','I'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('I',peca_I_0_180,peca_I_90_270,peca_I_0_180,peca_I_90_270);
    char pecaJ_0[4][4] {
        {'J','J','J','J'},
        {' ',' ',' ','J'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_J_90[4][4] {
        {' ','J',' ',' ',},
        {' ','J',' ',' '},
        {' ','J',' ',' '},
        {'J','J',' ',' '},
    };
    char peca_J_180[4][4] {
        {'J',' ',' ',' '},
        {'J','J','J','J'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_J_270[4][4] {
        {'J','J',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
    };
    inicializaPeca('J',pecaJ_0,peca_J_90,peca_J_180,peca_J_270);
    char peca_L_0[4][4] {
        {'L','L','L','L'},
        {'L',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_L_90[4][4] {
        {'L','L',' ',' '},
        {' ','L',' ',' '},
        {' ','L',' ',' '},
        {' ','L',' ',' '},
    };
    char peca_L_180[4][4] {
        {' ',' ',' ','L'},
        {'L','L','L','L'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_L_270[4][4] {
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L','L',' ',' '},
    };
    inicializaPeca('L',peca_L_0,peca_L_90,peca_L_180,peca_L_270);
    char peca_O_0_90_180_270[4][4] {
        {'O','O',' ',' '},
        {'O','O',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('O',peca_O_0_90_180_270,peca_O_0_90_180_270,peca_O_0_90_180_270,peca_O_0_90_180_270);
    char peca_S_0_180[4][4] {
        {' ','S','S',' '},
        {'S','S',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_S_90_270[4][4] {
        {'S',' ',' ',' '},
        {'S','S',' ',' '},
        {' ','S',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('S',peca_S_0_180,peca_S_90_270,peca_S_0_180,peca_S_90_270);
    char peca_T_0[4][4] {
        {'T','T','T',' '},
        {' ','T',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_T_90[4][4] {
        {' ','T',' ',' '},
        {'T','T',' ',' '},
        {' ','T',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_T_180[4][4] {
        {' ','T',' ',' '},
        {'T','T','T',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_T_270[4][4] {
        {'T',' ',' ',' '},
        {'T','T',' ',' '},
        {'T',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('T',peca_T_0,peca_T_90,peca_T_180,peca_T_270);
    char peca_Z_0_180[4][4] {
        {'Z','Z',' ',' '},
        {' ','Z','Z',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_Z_90_270[4][4] {
        {' ','Z',' ',' '},
        {'Z','Z',' ',' '},
        {'Z',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    inicializaPeca('Z',peca_Z_0_180,peca_Z_90_270,peca_Z_0_180,peca_Z_90_270);
    
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