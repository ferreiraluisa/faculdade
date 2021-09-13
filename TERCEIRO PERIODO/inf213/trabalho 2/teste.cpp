#include <iostream>
#include "Tetris.h"
using namespace std;

int main()
{
    Tetris game(5);
    bool tryAdd = game.adicionaForma(0, 1, 'T', 0);
    bool tryAdd2 = game.adicionaForma(0, 1, 'I', 90);
    bool tryAdd3 = game.adicionaForma(1, 4, 'S', 0);
    bool tryAdd4 = game.adicionaForma(3, 1, 'O', 0);
    game.imprimeJogo();
}