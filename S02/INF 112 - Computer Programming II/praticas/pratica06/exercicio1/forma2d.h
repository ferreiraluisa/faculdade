#ifndef INF112_FORMA2D_H
#define INF112_FORMA2D_H
#include "forma.h"

class Forma2D : public Forma{
    public:
        virtual double get_area() = 0;
        virtual double get_perimetro() = 0;
};

#endif 