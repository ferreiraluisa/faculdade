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
//construtor de copia
Tetris::Tetris(const Tetris &other){
    create();
    *this = other;
}
//operador de copia
Tetris &Tetris::operator=(const Tetris &other){
    if(this == &other) return *this;
    destroy();
    numColums = other.numColums;
    create();
    for(int i=0;i<numColums;i++){
        for(int j=0;j<alturas[i];j++){
            jogo[i][j] = other.jogo[i][j];
        }
    }
    return *this;
}

void Tetris::inicializaAltura(){
    for(int i=0;i<numColums;i++) alturas[i] = 1;
}

void Tetris::inicializaJogo(){
    for(int i=0;i<numColums;i++) {
        resizeGameHeightCapacity(i,2);
        jogo[i][0] = 'a';
        jogo[i][1] = ' ';
    }
}

void Tetris::create(){
    larguraPeca = new int[28];
    alturaPeca = new int[28];
    alturas = new int[numColums];
    inicializaAltura();
    jogo = new char *[numColums];
    for(int i=0;i<numColums;i++){
      jogo[i] = new char[2];  
      jogo[i][0] = 'a';
      jogo[i][1] = ' ';
    } 
    pecas = new char **[28];
    for(int i = 0;i<28;i++){
        pecas[i] = new char*[4];
        for(int j=0;j<4;j++){
            pecas[i][j] = new char[4];
        }
    }
    createPecas();
    resizeGameHeightCapacity(0,5);
    //inicializaJogo();
}
void Tetris::destroy(){
    delete[] alturas;
    delete[] larguraPeca;
    delete[] alturaPeca;
    for(int i=0;i<numColums;i++) delete[] jogo[i];
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
int Tetris::alturaMaxima() const{
    int maior = 0;
    for(int i=0;i<numColums;i++){
        if(alturas[i] > maior) maior = alturas[i];
    }

    return maior;
}
//fiz essa função para achar a menor altura pra ver quais linhas estão completas, caso eu não achasse eu iria acessar lugar na memória que não existe e daria erro
int Tetris::alturaMinima(){
    int menor = 9999;
    for(int i=0;i<numColums;i++){
        if(alturas[i] < menor) menor = alturas[i];
    }
    return menor;
}
//testei e deu certo! 0 erros no valgrind
bool Tetris::linhaCompleta(int linha){
    for(int i=0;i<numColums;i++){
        if(jogo[i][linha] == ' ') return false;
    }
    return true;
}
//testei e deu certo! 0 erros no valgrind
void Tetris::removePecaAltura(int pos, int c){
    char **aux = jogo;
    alturas[c] = alturas[c]-1;
    jogo = new char *[getNumColunas()];
    for(int i=0;i<getNumColunas();i++){
        jogo[i] = new char[alturas[i]];
     }
    for(int i=0;i<alturas[c];i++){
        if(i == pos){
            for(int j=i;j<alturas[c];j++){
                jogo[c][j] = aux[c][j+1];
            }
            break;
        }
        jogo[c][i] = aux[c][i];
    }
    for(int i=0;i<numColums;i++){
        delete[] aux[i];
    }
    delete[] aux;
}
//testei e deu certo! 0 erros no valgrind
void Tetris::removeLinha(int linha){
    for(int i=0;i<numColums;i++){
        removePecaAltura(linha, i);
    }
}

int Tetris::getPosIdRotacao(char id, int rotacao){
    switch (rotacao)
    {
    case 0:
        return getPosIdPeca(id);
    case 90:
        return getPosIdPeca(id)+1;
    case 180:
        return getPosIdPeca(id)+2;
    case 270:
        return getPosIdPeca(id)+3;
    default:
        return 0;
    }
}

int Tetris::getPosIdPeca(char id){
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
    int pecaId = getPosIdPeca(id);
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

void Tetris::setMedidasPeca(int largura, int altura, int &pos){
    larguraPeca[pos] = largura;
    alturaPeca[pos] = altura;
    pos++;
}

void Tetris::createPecas(){
    int aux = 0;
    char peca_I_0_180[4][4] {
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
        {'I',' ',' ', ' '},
    };
    setMedidasPeca(1,4,aux);
    
    char peca_I_90_270[4][4] {
        {'I','I','I','I'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,1,aux);

    inicializaPeca('I',peca_I_0_180,peca_I_90_270,peca_I_0_180,peca_I_90_270);
    char pecaJ_0[4][4] {
        {'J','J','J','J'},
        {' ',' ',' ','J'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,2,aux);
    char peca_J_90[4][4] {
        {' ','J',' ',' ',},
        {' ','J',' ',' '},
        {' ','J',' ',' '},
        {'J','J',' ',' '},
    };
    setMedidasPeca(2,4,aux);
    char peca_J_180[4][4] {
        {'J',' ',' ',' '},
        {'J','J','J','J'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,2,aux);
    char peca_J_270[4][4] {
        {'J','J',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
    };
    setMedidasPeca(2,4,aux);
    inicializaPeca('J',pecaJ_0,peca_J_90,peca_J_180,peca_J_270);
    char peca_L_0[4][4] {
        {'L','L','L','L'},
        {'L',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,2,aux);
    char peca_L_90[4][4] {
        {'L','L',' ',' '},
        {' ','L',' ',' '},
        {' ','L',' ',' '},
        {' ','L',' ',' '},
    };
    setMedidasPeca(2,4,aux);
    char peca_L_180[4][4] {
        {' ',' ',' ','L'},
        {'L','L','L','L'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,2,aux);
    char peca_L_270[4][4] {
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L','L',' ',' '},
    };
    setMedidasPeca(2,4,aux);
    inicializaPeca('L',peca_L_0,peca_L_90,peca_L_180,peca_L_270);
    char peca_O_0_90_180_270[4][4] {
        {'O','O',' ',' '},
        {'O','O',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(2,2,aux);
    inicializaPeca('O',peca_O_0_90_180_270,peca_O_0_90_180_270,peca_O_0_90_180_270,peca_O_0_90_180_270);
    char peca_S_0_180[4][4] {
        {' ','S','S',' '},
        {'S','S',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(3,2,aux);
    char peca_S_90_270[4][4] {
        {'S',' ',' ',' '},
        {'S','S',' ',' '},
        {' ','S',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(2,3,aux);
    inicializaPeca('S',peca_S_0_180,peca_S_90_270,peca_S_0_180,peca_S_90_270);
    char peca_T_0[4][4] {
        {'T','T','T',' '},
        {' ','T',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(3,2,aux);
    char peca_T_90[4][4] {
        {' ','T',' ',' '},
        {'T','T',' ',' '},
        {' ','T',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(2,3,aux);
    char peca_T_180[4][4] {
        {' ','T',' ',' '},
        {'T','T','T',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(3,2,aux);
    char peca_T_270[4][4] {
        {'T',' ',' ',' '},
        {'T','T',' ',' '},
        {'T',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(2,3,aux);
    inicializaPeca('T',peca_T_0,peca_T_90,peca_T_180,peca_T_270);
    char peca_Z_0_180[4][4] {
        {'Z','Z',' ',' '},
        {' ','Z','Z',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(3,2,aux);
    char peca_Z_90_270[4][4] {
        {' ','Z',' ',' '},
        {'Z','Z',' ',' '},
        {'Z',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(2,3,aux);
    inicializaPeca('Z',peca_Z_0_180,peca_Z_90_270,peca_Z_0_180,peca_Z_90_270);
    
}

void Tetris::resizeGameHeightCapacity(int c, int newcapacity){ //usei como fonte a funcao do resizeCapacity do MyVec na pratica5
    if(alturas[c] == newcapacity) return;

    char *colunaAntiga = jogo[c];

    jogo[c] = new char[newcapacity];

    for(int i=0;i<alturas[c];i++){
        jogo[c][i] = colunaAntiga[i];
    }

    alturas[c] = newcapacity;

    delete[] colunaAntiga;
}

void Tetris::eraseAlturas(int coluna){
    int *aux = alturas;
    alturas = new int[getNumColunas()-1];
    for(int i=0;i<getNumColunas();i++){
        if(i == coluna){
            for(int j =i;j<getNumColunas()-1;j++){
                alturas[j] = aux[j+1];
            }
            break;
        }
        alturas[i] = aux[i];
    }
    delete[] aux;
}

//funcoes publicas, ditas na especificação
char Tetris::get(int colums, int row) const { //retorna um caractere que representa o estado de tal pixel no jogo atual
    return jogo[colums][row];
}
//esta dando certo depois do teste! 0 erros no valgrind :D
void Tetris::removeColuna(int coluna){ //remove a coluna do jogo (diminuindo, assim, sua largura)
    eraseAlturas(coluna);
    char **aux = jogo;
    jogo = new char *[getNumColunas()-1];
     for(int i=0;i<getNumColunas()-1;i++){
         jogo[i] = new char[alturas[i]];
     }
    for(int i=0;i<numColums;i++){
        if(i==coluna){
            for(int j=i;j<numColums-1;j++){
                for(int k=0;k<alturas[coluna++];k++){
                    jogo[j][k] = aux[j+1][k];
                }
            }
            break;
        }
        for(int j=0;j<alturas[i];j++) jogo[i][j] = aux[i][j];
        
    }
    for(int i=0;i<numColums;i++){
         delete[] aux[i];
    }
    delete[] aux;
    numColums = numColums -1;

}
void Tetris::removeLinhasCompletas(){ //remove todos os pixels do jogo que estiverem em linhas completas
    for(int i=0;i<alturaMinima();i++){
        if(linhaCompleta(i)){
            removeLinha(i);
        }
    }
}
int Tetris::getNumColunas() const{ //retorna o número de colunas (largura) do jogo Tetris. Esse número deverá ser igual ao valor passado pelo construtor do jogo
    return numColums;
}
int Tetris::getAltura(int colum) const{ //retorna a altura da coluna c do jogo
    return alturas[colum];
}
int Tetris::getAltura() const { //retorna a altura maxima do jogo atual
    return alturaMaxima();
}
bool Tetris::adicionaForma(int coluna, int linha, char id, int rotacao){ //retorna se é possível ou não adicionar a peça
    int pos = getPosIdRotacao(id,rotacao);
    return false;
}

//funcoes para teste
void Tetris::imprimePeca(){
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

void Tetris::imprimeJogo(){
    for(int i=0;i<numColums;i++){
        for(int j=0;j<alturas[i];j++){
            cout<<jogo[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"fim"<<endl;
}

void Tetris::imprimeAltura(int c){
    cout<<alturas[c]<<endl;
}