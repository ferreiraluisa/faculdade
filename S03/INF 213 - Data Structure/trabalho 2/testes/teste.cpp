#include <iostream>
#include "Tetris.h"
using namespace std;

int main()
{
    Tetris a(15);

    a.adicionaForma(0,0,'O',0);
    a.adicionaForma(14,0,'O',0);
    a.adicionaForma(5,0,'O',0);
    a.adicionaForma(200,200,'O',0);
    a.adicionaForma(200,0,'O',0);

    a.removeColuna(0);
    a.removeColuna(1);
    a.removeColuna(11);
   // a.imprimeJogo();

}