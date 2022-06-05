#ifndef INF112_ESFERA_H
#define INF112_ESFERA_H
#include "forma3d.h"

class Esfera : public Forma3D{
    private:
        std::string _nome ; 
        std::string _cor; 
        double _raio;
    public:
        Esfera(std::string nome, std::string cor, double raio);
        ~Esfera();
        virtual std::string get_cor() override;
        virtual std::string get_nome() override;
        virtual double get_volume() override ;
};

#endif 