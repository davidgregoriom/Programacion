#include "matrizgeneral.h"

matrizGeneral::matrizGeneral()
{//Constructor por defecto
    filas=0;
    columnas=0;
}

matrizGeneral::matrizGeneral(int f,int c)
{//Constructor con parámetros
    std::vector<double>aux;
    aux.resize(c,0);
    mat.push_back(aux);
    mat.resize(f,aux);

    filas=f;
    columnas=c;
}

double matrizGeneral::getValue(int f,int c)
{
    if(f<0 or f>filas or c<0 or c>columnas)
    {//Si los índices están fuera de rango=> excepción
        throw std::string{"out_of_range;"};
    }
    else
    {//Si está dentro devolvemos el elemento de posición [f,c]
        return mat.at(f).at(c);
    }
}

void matrizGeneral::setValue(int f,int c, double valor)
{
    if(f<0 or f>filas or c<0 or c>columnas)
    {//Si los índices están fuera de rango=> excepción
        throw std::string{"out_of_range;"};
    }
    else
    {//Si está dentro escribimos valor en el elemento de posición [f,c]
        mat.at(f).at(c)=valor;
    }
}

void matrizGeneral::mostrar(void)
{//recorremos mostrando elementos de la matriz
    std::cout<<"*********"<<std::endl;
    for(auto f:mat)
    {
        for(auto elem:f)
        {
            std::cout<<elem<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"*********"<<std::endl;
}
