#ifndef INF112_ARTIGOSHIGIENE_H
#define INF112_ARTIGOSHIGIENE_H
#include "produto.h"

class ArtigosHigiene : public Produto {
    private:
        int _codigo;
        std::string _descricao;
        double _preco;
        double _lucro;
    public:
        ArtigosHigiene(int codigo, std::string descricao,double preco);
        ~ArtigosHigiene();
        virtual int get_codigo() override;
        virtual std::string get_descricao() override;
        virtual double get_preco_de_compra() override;
        virtual double gerarprecodevenda() override;
        virtual double get_lucro() override;
};

#endif