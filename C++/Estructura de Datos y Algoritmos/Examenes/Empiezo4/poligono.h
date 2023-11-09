#ifndef POLIGONO_H
#define POLIGONO_H
#include <figura.h>


class poligono:public figura
{
public:
    poligono();

private:
    int lado;
    float numero_lados;
    float apotema;
};

#endif // POLIGONO_H
