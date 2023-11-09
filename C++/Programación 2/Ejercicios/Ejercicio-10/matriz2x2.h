#ifndef MATRIZ2X2_H
#define MATRIZ2X2_H

#include "matrizgeneral.h"

class Matriz2x2:public matrizGeneral
{//Matriz 2x2 hereda públicamente de matriz general
public:
    Matriz2x2();

    double getDeterminant();
    Matriz2x2 getInverse();
    Matriz2x2 getTraspose();
    Matriz2x2 getAdjugate();
};

#endif // MATRIZ2X2_H
