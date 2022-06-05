#ifndef INF112_FORMA3D_H
#define INF112_FORMA3D_H
#include "forma.h"

class Forma3D : public Forma{
    public:
        virtual double get_volume() = 0;
};

#endif 