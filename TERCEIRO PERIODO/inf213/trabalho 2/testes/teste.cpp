#include <iostream>
#include "Tetris.h"
using namespace std;

int main()
{
    Tetris a(4);
    Tetris b;
    Tetris c(17);
    
    // c.adicionaForma(0,17,'I',270);
    // c.imprimeJogo(); aparentemente deu certo!



    int coluna = 0;
    int linha = 0;
    char Tipo = ' ';
    int rotacao = 0;

    // while (true)
    // {
    //     std::cin >> coluna >> linha >> Tipo >> rotacao;
    //     if (Tipo == 'Q')
    //     {
    //         return 0;
    //     }

    //     std::cout << a.adicionaForma(coluna, linha, Tipo, rotacao);
    //     b = a;
    //     b.printMatrix();
    //     b.removeLinhasCompletas();
    //     b.printMatrix();
    // }

    a.adicionaForma(0, 0, 'I', 90);
    a.adicionaForma(0, 5, 'I', 0);
    a.adicionaForma(1, 5, 'I', 0);
    a.imprimeJogo();
    a.adicionaForma(2, 5, 'I', 0);
    a.removeColuna(2);

    a.imprimeJogo();

   

    // b = a;
    // b.imprimeJogo();
    // b.removeLinhasCompletas();
    // b.imprimeJogo();

}