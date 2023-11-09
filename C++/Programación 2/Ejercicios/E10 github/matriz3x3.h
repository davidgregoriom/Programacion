#ifndef MATRIZ3X3_H
#define MATRIZ3X3_H

#include "matrizgeneral.h"
#include <array>

class Matriz3x3: public matrizGeneral
{//Matriz 3x3 hereda públicamente de matriz general
public:
    Matriz3x3();

    double getDeterminant();
    Matriz3x3 getInverse();
    Matriz3x3 getTraspose();
    Matriz3x3 getAdjugate();
};

#endif // MATRIZ3X3_H
