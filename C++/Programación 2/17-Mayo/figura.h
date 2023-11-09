#ifndef FIGURA_H
#define FIGURA_H
#include <math.h>

class figura
{
public:
    figura(); //los contructores se llaman de arriba a abajo en jerarquia y los destructores de abajo a arriba
    virtual ~figura(){} //hay que hace run destructor virtual pero no se el simbolo
    float getArea() const;
    virtual void computeArea() = 0;//el virtual indica que es polimorfica, el = 0 indica que es pura(la funcion no lo hace nunca)
    //sin el = 0 podria ser virtual e igual estar definida en figura para que sirva para algunos y otros no
protected:
    float area;
};

#endif // FIGURA_H
