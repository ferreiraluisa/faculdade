#ifndef INF112_CIRCULO_H
#define INF112_CIRCULO_H
#include "forma2d.h"

class Circulo : public Forma2D {
    private:
        std::string _nome;
        std::string _cor;
        double _raio;
    public:
        Circulo(std::string nome, std::string cor, double raio);
        ~Circulo();
        virtual std::string get_cor() override;
        virtual std::string get_nome() override;
        virtual double get_area() override ;
        virtual double get_perimetro() override;

};

#endif 