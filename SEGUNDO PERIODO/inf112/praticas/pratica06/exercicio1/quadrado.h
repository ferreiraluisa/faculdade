#ifndef INF112_QUADRADO_H
#define INF112_QUADRADO_H
#include "forma2d.h"

class Quadrado : public Forma2D{
    private:
        std::string _nome ; 
        std::string _cor; 
        double _lado;
    public:
        Quadrado(std::string nome, std::string cor, double lado);
        ~Quadrado();
        virtual std::string get_cor() override;
        virtual std::string get_nome() override;
        virtual double get_area() override ;
        virtual double get_perimetro() override;
};

#endif 
