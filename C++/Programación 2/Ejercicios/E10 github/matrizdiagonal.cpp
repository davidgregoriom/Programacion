#include "matrizdiagonal.h"

MatrizDiagonal::MatrizDiagonal(int dimension):matrizGeneral(dimension,dimension)
{//Constructor que inicializa matriz general a dimensión,dimension y pone a 0 todos sus elementos

}

MatrizDiagonal::MatrizDiagonal(int dimension,std::vector<double> diagonal):matrizGeneral(dimension,dimension)
{
    if(dimension>diagonal.size())
    {//Si la diagonal es  mayor que la dimensión=> excepción
        throw std::string{"size_mismatch"};
    }
    else
    {//Si no inicializamos los valores de la diagonal
        for(int i{0};i<diagonal.size();i++)
        {
            setValue(i,i,diagonal.at(i));
        }
    }
}

double MatrizDiagonal::getDeterminant()
{//El determinante de una matriz diagonal es el producto de los elementos de su diagonal
    double ret=1;

    for(int i{0};i<getNcols();i++)
    {
        ret*=getValue(i,i);
    }

    return ret;
}

MatrizDiagonal MatrizDiagonal::getInverse()
{//La inversa de la matriz diagonal es otra diagonal con los elementos de la diagonal invertidos
    int dim=getNcols();
    MatrizDiagonal aux(dim);
    for(int i{0};i<dim;i++)
    {//para cada elemento de la diagonal asignamos 1/valor
        double temp=getValue(i,i);
        aux.setValue(i,i,1/temp);
    }

    return aux;
}

MatrizDiagonal MatrizDiagonal::getTraspose()
{//La traspuesta de una diagonal es la misma diagonal
    int dim=getNcols();
    MatrizDiagonal aux(dim);
    for(int i{0};i<dim;i++)
    {
        aux.setValue(i,i,getValue(i,i));
    }

    return aux;
}

MatrizDiagonal MatrizDiagonal::getAdjugate()
{//Como en matriz 3x3 pero solo para los elementos de la diagonal
    int dim=getNcols();
    double detAux=1;

    MatrizDiagonal aux(dim);

    for(int i{0};i<dim;i++)
    {
        for(int j{0};j<dim;j++)
        {
            if(j==i)
            {
                continue; //Nos lo saltamos
            }
            else
            {
                detAux*=getValue(j,j);
            }
        }
        aux.setValue(i,i,detAux);
        detAux=1; //"Reseteamos" para el calculo de la siguiente vuelta
    }

    return aux;
}
