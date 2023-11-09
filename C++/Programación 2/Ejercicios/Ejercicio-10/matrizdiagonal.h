#ifndef MATRIZDIAGONAL_H
#define MATRIZDIAGONAL_H

#include "matrizgeneral.h"

class MatrizDiagonal:public matrizGeneral
{
public:
    MatrizDiagonal(int dimension);
    MatrizDiagonal(int dimension,const std::vector<double>& diagonal);

    double getDeterminant();
    MatrizDiagonal getInverse();
    MatrizDiagonal getTraspose();
    MatrizDiagonal getAdjugate();
};

#endif // MATRIZDIAGONAL_H
