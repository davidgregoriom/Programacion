#ifndef MATRIZGENERAL_H
#define MATRIZGENERAL_H

#include <iostream>
#include <vector>
#include <string>

class matrizGeneral
{//Clase base con la matriz de dimensiones genericas
public:
    matrizGeneral();
    matrizGeneral(int f,int c);

    double getValue(int f,int c);
    void setValue(int f,int c, double valor);

    void mostrar();

    int getNcols(){return columnas;}
    int getNfils(){return filas;}
private:
    std::vector<std::vector<double>> mat;
    int filas;
    int columnas;
};

#endif // MATRIZGENERAL_H
