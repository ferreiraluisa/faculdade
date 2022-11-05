#ifndef INF112_CUBO_H
#define INF112_CUBO_H
#include "forma3d.h"

class Cubo : public Forma3D{
    private:
        std::string _nome ; 
        std::string _cor; 
        double _lado;
    public:
        Cubo(std::string nome, std::string cor, double lado);
        ~Cubo();
        virtual std::string get_cor() override;
        virtual std::string get_nome() override;
        virtual double get_volume() override ;
};

#endif 