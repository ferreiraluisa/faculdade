#ifndef INF112_REMEDIO_H
#define INF112_REMEDIO_H
#include "produto.h"

class Remedio : public Produto{
    private:
        int _codigo;
        std::string _descricao;
        double _preco;
        double _desconto;
        double _lucro;
    public:
        Remedio(int codigo, std::string descricao,double preco, double desconto, double lucro);
        ~Remedio();
        double get_desconto();
        virtual int get_codigo() override;
        virtual std::string get_descricao() override;
        virtual double get_preco_de_compra() override;
        virtual double gerarprecodevenda() override;
        virtual double get_lucro() override;
};

#endif