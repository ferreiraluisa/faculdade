#ifndef INF112_PRODUTOS_H
#define INF112_PRODUTOS_H
#include <string>

class Produto{
    public:
        virtual int get_codigo() = 0;
        virtual std::string get_descricao() = 0;
        virtual double gerarprecodevenda() = 0;
        virtual double get_lucro() = 0;
        virtual double get_preco_de_compra() = 0;
};

#endif