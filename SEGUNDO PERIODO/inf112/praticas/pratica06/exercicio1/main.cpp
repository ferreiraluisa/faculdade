#include <iostream>
#include "circulo.h"
#include "quadrado.h"
#include "triangulo.h"
#include "esfera.h"
#include "cubo.h"

int main(){
    Quadrado obj0("Quadrado","Amarelo",2); // 2p = 8, A = 4
    Triangulo obj1("Triangulo","Vermelho",4,5,3); //2p = 12, A = 6
    Circulo obj2("Circulo", "Verde", 2); // 2p = 12.56636 , A = 12,56636
    Esfera obj3("Esfera", "Rosa", 4); // V = 268.08
    Cubo obj4("Cubo", "Colorido", 2); // V = 8

    std::cout<<"----------"<<obj0.get_nome()<<"----------"<<std::endl;
    std::cout<<"Perimetro = "<<obj0.get_perimetro()<<std::endl;
    std::cout<<"Area = "<<obj0.get_area()<<std::endl;
    std::cout<<"----------"<<obj1.get_nome()<<"----------"<<std::endl;
    std::cout<<"Perimetro = "<<obj1.get_perimetro()<<std::endl;
    std::cout<<"Area = "<<obj1.get_area()<<std::endl;
    std::cout<<"----------"<<obj2.get_nome()<<"----------"<<std::endl;
    std::cout<<"Perimetro = "<<obj2.get_perimetro()<<std::endl;
    std::cout<<"Area = "<<obj2.get_area()<<std::endl;
    std::cout<<"----------"<<obj3.get_nome()<<"----------"<<std::endl;
    std::cout<<"Volume = "<<obj3.get_volume()<<std::endl;
    std::cout<<"----------"<<obj4.get_nome()<<"----------"<<std::endl;
    std::cout<<"Volume = "<<obj4.get_volume()<<std::endl;

    return 0;

}