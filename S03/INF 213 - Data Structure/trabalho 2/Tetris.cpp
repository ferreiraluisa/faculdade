#include "Tetris.h"
#include <iostream>
using namespace std;


//construtores
Tetris::Tetris(){
    numColums = 0;
    create();
}
Tetris::Tetris(int _numcolums){
    numColums = _numcolums;
    create();
}
Tetris::~Tetris(){
    destroy();
}
//construtor de copia
Tetris::Tetris(const Tetris &other){
    numColums = other.numColums;
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
        alturas[i] = other.alturas[i];
        delete[] jogo[i];
        jogo[i] = new char[other.alturas[i]];
    }
    for(int i=0;i<numColums;i++){
        for(int j=0;j<alturas[i];j++){
            jogo[i][j] = other.jogo[i][j];
        }
    }
    return *this;
}

void Tetris::create(){
    larguraPeca = new int[28];
    for(int i = 0; i < 28; i ++)
        larguraPeca[i] = 0;
    alturaPeca = new int[28];
    for(int i = 0; i < 28; i ++)
        alturaPeca[i] = 0;
    alturas = new int[numColums];
    for(int i = 0; i < numColums; i ++)
        alturas[i] = 0;
    jogo = new char *[numColums];
    for(int i=0;i<numColums;i++){
      jogo[i] = new char[1];
      jogo[i][0] = ' ';
    } 
    pecas = new char **[28];
    for(int i = 0;i<28;i++){
        pecas[i] = new char*[4];
        for(int j=0;j<4;j++){
            pecas[i][j] = new char[4];
        }
    }
    for(int i = 0;i<28;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                pecas[i][j][k] = ' ';
            }
        }
    }
    createPecas(); //inicializa as peças
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
int Tetris::alturaMinima() const{
    int menor = alturas[0];
    for(int i=1;i<numColums;i++){
        if(alturas[i] < menor) menor = alturas[i];
    }
    return menor;
}

bool Tetris::linhaCompleta(int linha){
    for(int i=0;i<numColums;i++){
        if(jogo[i][linha] == ' ') return false;
    }
    return true;
}

void Tetris::removePecaAltura(int linha, int coluna){ //remover a peça na linha correspondente a linha que está completa
    char *aux = jogo[coluna];
    alturas[coluna] = alturas[coluna]-1;
    jogo[coluna] = new char[alturas[coluna]];
    for(int i=0;i<alturas[coluna];i++){
        if(linha == i){
            for(int j=i;j<alturas[coluna];j++){
                jogo[coluna][j] = aux[j+1];
            }
            break;
        }
        jogo[coluna][i] = aux[i];
    }

    delete[] aux;
    
}

void Tetris::removeLinha(int linha){ //vai chamar a removePecaAltura pra remover a peca na linha de todas as colunas
    for(int i=0;i<numColums;i++){
        removePecaAltura(linha, i);
    }
}

int Tetris::getPosIdRotacao(char id, int rotacao){ //vai pegar qual a posicao do array 3d pecas que a matriz 4x4 da peça com id x e rotacao y se encontra
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

int Tetris::getPosIdPeca(char id){//vai pegar qual a posicao do array 3d pecas que a matriz 4x4 da peça com id x se encontra
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

void Tetris::inicializaPeca(char id, const char peca0[4][4], const char peca90[4][4], const char peca180[4][4], const char peca270[4][4]){ //vai inicializar todas as 28 posicoes do array pecas com as matrizes 4x4 correspondentes
    int pecaId = getPosIdPeca(id);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            pecas[pecaId][i][j] = peca0[j][i];    
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            pecas[pecaId+1][i][j] = peca90[j][i];    
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            pecas[pecaId+2][i][j] = peca180[j][i];    
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            pecas[pecaId+3][i][j] = peca270[j][i];    
        }
    }
}

void Tetris::setMedidasPeca(int largura, int altura, int &pos){ //pegar a medida de cada peca para auxiliar no AdicionaForma
    larguraPeca[pos] = largura;
    alturaPeca[pos] = altura;
    pos++;
}

void Tetris::createPecas(){ //inicializa peca e medidas, utiliza a funcao inicializaPeca e setMedidasPeca
    int aux = 0;
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

    setMedidasPeca(1,4,aux); //0
    setMedidasPeca(4,1,aux); //90 
    setMedidasPeca(1,4,aux); //180
    setMedidasPeca(4,1,aux); //270

    inicializaPeca('I',peca_I_0_180,peca_I_90_270,peca_I_0_180,peca_I_90_270);
    char pecaJ_0[4][4] {
        {' ',' ',' ','J'},
        {'J','J','J','J'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,2,aux);
    char peca_J_90[4][4] {
        {'J','J',' ',' ',},
        {' ','J',' ',' '},
        {' ','J',' ',' '},
        {' ','J',' ',' '},
    };
    setMedidasPeca(2,4,aux);
    char peca_J_180[4][4] {
        {'J','J','J','J'},
        {'J',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,2,aux);
    char peca_J_270[4][4] {
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J','J',' ',' '},
    };
    setMedidasPeca(2,4,aux);
    inicializaPeca('J',pecaJ_0,peca_J_90,peca_J_180,peca_J_270);
    char peca_L_0[4][4] {
        {'L',' ',' ',' '},
        {'L','L','L','L'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,2,aux);
    char peca_L_90[4][4] {
        {' ','L',' ',' '},
        {' ','L',' ',' '},
        {' ','L',' ',' '},
        {'L','L',' ',' '},
    };
    setMedidasPeca(2,4,aux);
    char peca_L_180[4][4] {
        {'L','L','L','L'},
        {' ',' ',' ','L'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(4,2,aux);
    char peca_L_270[4][4] {
        {'L','L',' ',' '},
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
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
    setMedidasPeca(2,2,aux);
    setMedidasPeca(2,2,aux);
    setMedidasPeca(2,2,aux);
    inicializaPeca('O',peca_O_0_90_180_270,peca_O_0_90_180_270,peca_O_0_90_180_270,peca_O_0_90_180_270);
    char peca_S_0_180[4][4] {
        {'S','S',' ',' '},
        {' ','S','S',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_S_90_270[4][4] {
        {' ','S',' ',' '},
        {'S','S',' ',' '},
        {'S',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(3,2,aux); //0
    setMedidasPeca(2,3,aux); //90
    setMedidasPeca(3,2,aux); //180
    setMedidasPeca(2,3,aux); //270
    inicializaPeca('S',peca_S_0_180,peca_S_90_270,peca_S_0_180,peca_S_90_270);
    char peca_T_0[4][4] {
        {' ','T',' ',' '},
        {'T','T','T',' '},
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
        {'T','T','T',' '},
        {' ','T',' ',' '},
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
        {' ','Z','Z',' '},
        {'Z','Z',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char peca_Z_90_270[4][4] {
        {'Z',' ',' ',' '},
        {'Z','Z',' ',' '},
        {' ','Z',' ',' '},
        {' ',' ',' ',' '},
    };
    setMedidasPeca(3,2,aux);
    setMedidasPeca(2,3,aux);
    setMedidasPeca(3,2,aux);
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
    for(int i=alturas[c];i<newcapacity;i++){
        jogo[c][i] = ' ';
    }

    alturas[c] = newcapacity;

    delete[] colunaAntiga;
}

void Tetris::eraseAlturas(int coluna){ //apagar no array de altura a posicao da coluna que sera removida
    int *aux = alturas;
    int cont =0;
    alturas = new int[numColums-1];
    for(int i=0;i<numColums;i++){
        if(i == coluna){
            for(int j =i;j<numColums-1;j++){
                alturas[j] = aux[j+1];
            }
            
            break;
        }
        alturas[i] = aux[i];
    }

    delete[] aux;
}
void Tetris::inserePeca(int pos, int coluna, int linha){
    for (int i = 0; i < alturaPeca[pos]; i++){
        for (int j = 0; j < larguraPeca[pos]; j++){
            if (pecas[pos][j][i] != ' '){
                int colunaNova = coluna+j;
                int linhaNova =linha-(alturaPeca[pos]-1-i)+1;//esse calculo eu fui fazendo no papel até dar um resultado geral pros cenários que eu criei
                if (linhaNova >= alturas[coluna + j]){
                    resizeGameHeightCapacity(coluna + j, linhaNova);
                }
            }
        }
    }

    for (int i = 0; i < alturaPeca[pos]; i++){
        for (int j = 0; j < larguraPeca[pos]; j++){
            if (pecas[pos][j][i] != ' '){
                int linhaAux = i +abs(alturaPeca[pos]-1-linha);//esse calculo eu fui fazendo no papel até dar um resultado geral pros cenários que eu criei
                jogo[coluna + j][linhaAux] = pecas[pos][j][i];
            }
        }   
    }
}
//funcoes publicas, ditas na especificação

char Tetris::get(int colums, int row) const { //retorna um caractere que representa o estado de tal pixel no jogo atual
    if(colums < numColums && row < alturas[colums]) return jogo[colums][row];
    return ' ';
}

void Tetris::removeColuna(int coluna){ //remove a coluna do jogo (diminuindo, assim, sua largura)
    char *auxColuna = jogo[coluna];

    for(int i=coluna;i<numColums-1;i++){
        jogo[i] = jogo[i+1];
    }
    
    delete[] auxColuna;
    eraseAlturas(coluna);
    numColums = numColums -1;
}
void Tetris::removeLinhasCompletas(){ //remove todos os pixels do jogo que estiverem em linhas completas
    for(int i=alturaMinima()-1;i>=0;i--){
        if(linhaCompleta(i)){
            removeLinha(i);
        }
    }
    for(int i=0;i<numColums;i++){
        int contCharLivre = 0;
        for(int j = alturas[i]-1;j>=0;j--){
            if(jogo[i][j] !=' ') break;
            contCharLivre++;
        }
        if(contCharLivre > 0){
            char *colunaAux = jogo[i];
            int alturaNova = alturas[i] - contCharLivre; //talvez -1 se der errado tenta aqui
            jogo[i] = new char[alturaNova];
            alturas[i] = alturaNova;
            for(int j=0;j<alturas[i];j++){
                jogo[i][j] = colunaAux[j];
            }
            

            delete[] colunaAux;

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
        for(int i=0;i<alturaPeca[pos];i++){
            for(int j=0;j<larguraPeca[pos];j++){
                if(pecas[pos][j][i] != ' '){
                    int colunaPeca = coluna+j;
                    int linhaPeca = linha+i-(alturaPeca[pos]-1); //esse calculo eu fui fazendo no papel até dar um resultado geral pros cenários que eu criei
                    if(linhaPeca<0 || colunaPeca<0 || colunaPeca>numColums-1) return false; //se estiver fora do "retangulo" do jogo não pode ser inserida.
                    if(linhaPeca < alturas[colunaPeca]){ //se a altura da peca for maior que a altura da coluna atual não precisa nem fazer o teste se tem espaço vazio já que não existe esse lugar na memória ainda, logo não tem nada lá e é possível encaixar a peça
                        if(jogo[colunaPeca][linhaPeca] != ' ') return false;
                    }
                } 
            }
        }

    inserePeca(pos,coluna,linha); //se tudo der certo, vai inserir

    return true;
}

//funcoes para teste
void Tetris::imprimePeca(){
    char inicio = 'I';
    cout<<"-------------PECA-------------"<<endl;
    for(int i=0;i<28;i++){
        if(i%4==0)cout<<"-------------PECA-------------"<<endl;
       for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                cout<<pecas[i][j][k]<<" ";
            }
            cout<<endl;
       } 
       cout<<endl;   
    }
    
}

void Tetris::imprimeJogo(){
    for(int i=0;i<numColums;i++){
        for(int j=0;j<alturas[i];j++){
            cout<<jogo[i][j];
        }
        cout<<"alturas "<<alturas[i]<<" - ";
        cout<<endl;
    }
    cout<<"fim"<<endl;
}

void Tetris::imprimeAltura(int c){
    cout<<alturas[c]<<endl;
}