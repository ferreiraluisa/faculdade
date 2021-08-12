#ifndef INF112_TRIANGULO_H
#define INF112_TRIANGULO_H
#include "forma2d.h"

class Triangulo : public Forma2D{
    private:
        std::string _nome;
        std::string _cor;
        double _lado_a;
        double _lado_b;
        double _lado_c;

    public:
        Triangulo(std::string nome, std::string cor, double ladoa, double ladob, double ladoc);
        ~Triangulo();
        virtual std::string get_cor() override;
        virtual std::string get_nome() override;
        virtual double get_area() override ;
        virtual double get_perimetro() override;

};

#endif 