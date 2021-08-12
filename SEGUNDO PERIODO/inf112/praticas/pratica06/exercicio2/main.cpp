#include <iostream>
#include "remedio.h"
#include "artigoshigiene.h"

int main(){
    Remedio remedio1(7578, "Advil Ibuprofeno 400mg", 5, 1.3 , 0.4); //Preco de venda = 5.7
    Remedio remedio2(8647, "Loratamed Loratadina 10mg", 18, 2.25, 0.35); //Preco de venda = 22.05
    ArtigosHigiene artigo1(2315, "Escova de dente ORAL B num 35 Macia", 15); //Preco de venda = 19.5
    ArtigosHigiene artigo2(4789, "Desodorante Aerosol Leite de Rosas", 16.5); //Preco de venda = 21.45

    std::cout<<"------------"<<remedio1.get_descricao()<<"------------"<<std::endl;
    std::cout<<"Codigo do produto: "<<remedio1.get_codigo()<<std::endl;
    std::cout<<"Preco inicial: R$"<<remedio1.get_preco_de_compra()<<std::endl;
    std::cout<<"Taxa de lucro: "<<remedio1.get_lucro()<<std::endl;
    std::cout<<"Desconto do laboratorio: R$"<<remedio1.get_desconto()<<std::endl;
    std::cout<<"Preco final: R$" <<remedio1.gerarprecodevenda()<<std::endl;

    std::cout<<"------------"<<remedio2.get_descricao()<<"------------"<<std::endl;
    std::cout<<"Codigo do produto: "<<remedio2.get_codigo()<<std::endl;
    std::cout<<"Preco inicial: R$"<<remedio2.get_preco_de_compra()<<std::endl;
    std::cout<<"Taxa de lucro: "<<remedio2.get_lucro()<<std::endl;
    std::cout<<"Desconto do laboratorio: R$"<<remedio2.get_desconto()<<std::endl;
    std::cout<<"Preco final: R$" <<remedio2.gerarprecodevenda()<<std::endl;

    std::cout<<"------------"<<artigo1.get_descricao()<<"------------"<<std::endl;
    std::cout<<"Codigo do produto: "<<artigo1.get_codigo()<<std::endl;
    std::cout<<"Preco inicial: R$"<<artigo1.get_preco_de_compra()<<std::endl;
    std::cout<<"Taxa de lucro: "<<artigo1.get_lucro()<<std::endl;
    std::cout<<"Preco final: R$" <<artigo1.gerarprecodevenda()<<std::endl;
    
    std::cout<<"------------"<<artigo2.get_descricao()<<"------------"<<std::endl;
    std::cout<<"Codigo do produto: "<<artigo2.get_codigo()<<std::endl;
    std::cout<<"Preco inicial: R$"<<artigo2.get_preco_de_compra()<<std::endl;
    std::cout<<"Taxa de lucro: "<<artigo2.get_lucro()<<std::endl;
    std::cout<<"Preco final: R$" <<artigo2.gerarprecodevenda()<<std::endl;

    return 0;
}