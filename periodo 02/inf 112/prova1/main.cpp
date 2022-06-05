#include <iostream>
#include "conta.h"
#include "contacorrente.h"
#include "contapoupanca.h"

double ContaPoupanca::_rendimento = 2.50;

int main(){
    ContaCorrente *obj1 = new ContaCorrente("Pedro","231654789",2400);
    ContaPoupanca *obj2 = new ContaPoupanca("Julio","258147369",5200);
    ContaPoupanca *obj3 = new ContaPoupanca("Luisa","123456789",3400);

    std::cout<<"------------Conta 1------------"<<std::endl;
    std::cout<<"Saldo = "<<obj1->get_saldo()<<std::endl; //imprimir : 2400
    std::cout<<"------------Conta 2------------"<<std::endl;
    std::cout<<"Rendimento = "<<obj2->_rendimento<<std::endl; //imprimir 2.5
    std::cout<<"Saldo = "<<obj2->get_saldo()<<std::endl; //imprimir : (5200) + (5200*(2.5/100)) = 5330
    obj2->muda_rendimento(4.00);
    std::cout<<"------------Conta 3------------"<<std::endl;
    std::cout<<"Rendimento = "<<obj3->_rendimento<<std::endl; //imprimir 4
    std::cout<<"Saldo = "<<obj3->get_saldo()<<std::endl; //imprimir : (3400) + (3400*(4/100)) = 3536

    delete obj1;
    delete obj2;
    delete obj3;

    return 0;
}