#include "matriz3x3.h"

Matriz3x3::Matriz3x3():matrizGeneral(3,3)
{//Constructor que llama al constructor de la matriz general

}

double Matriz3x3::getDeterminant()
{//Calculo determinante mediante Sarrus
    return getValue(0,0)*getValue(1,1)*getValue(2,2)+getValue(1,0)*getValue(2,1)*getValue(0,2)+getValue(2,0)*getValue(0,1)*getValue(1,2)
            -getValue(0,2)*getValue(1,1)*getValue(2,0)-getValue(1,2)*getValue(2,1)*getValue(0,0)-getValue(2,2)*getValue(0,1)*getValue(1,0);
}
Matriz3x3 Matriz3x3::getInverse()
{//A^-1=(1/|A|)*Adj(Atraspuesta)
    Matriz3x3 retorno;
    //int cols=getNcols();
    //int fils=getNfils();

    if(getDeterminant()==0)
    {
        throw std::string{"no invertible"};
    }
    else
    {
        Matriz3x3 aux1=getTraspose();
        Matriz3x3 aux2=aux1.getAdjugate();

        try{
            double det=getDeterminant();
            for(int f{0};f<3;f++)
            {
                for(int c{0};c<3;c++)
                {
                    retorno.setValue(f,c,aux2.getValue(f,c)/det);
                }
            }
        }
        catch(std::string s)
        {
            std::cout<<s<<std::endl;
        }
    }

    return retorno;
}
Matriz3x3 Matriz3x3::getTraspose()
{//Cambiamos filas por columnas
    Matriz3x3 retorno;
    //int cols=getNcols();
    //int fils=getNfils();

    for(int i{0};i<3;i++)
    {
        for(int j{0};j<3;j++)
        {
            retorno.setValue(i,j,getValue(j,i));
        }
    }

    return retorno;
}

Matriz3x3 Matriz3x3::getAdjugate()
{//Calculamos la adjunta de la matriz
    Matriz3x3 retorno;

    // |a b|
    // |c d|
    //det= a*b-b*c;

    //Para calcula la adjunta de una matriz 3x3, cada elemento será el terminante de
    //la matriz original quitando la fila y columna indicada por sus indices
    //Adjunta=
    //| det00 det01 det02|
    //| det10 det11 det12|
    //| det20 det21 det22|
    retorno.setValue(0,0,getValue(1,1)*getValue(2,2)-getValue(2,1)*getValue(1,2));
    retorno.setValue(0,1,-getValue(1,0)*getValue(2,2)+getValue(2,0)*getValue(1,2));
    retorno.setValue(0,2,getValue(1,0)*getValue(2,1)-getValue(2,0)*getValue(1,1));

    retorno.setValue(1,0,-getValue(0,1)*getValue(2,2)+getValue(2,1)*getValue(0,2));
    retorno.setValue(1,1,getValue(0,0)*getValue(2,2)-getValue(2,0)*getValue(0,2));
    retorno.setValue(1,2,-getValue(0,0)*getValue(2,1)+getValue(2,0)*getValue(0,1));

    retorno.setValue(2,0,getValue(0,1)*getValue(1,2)-getValue(1,1)*getValue(0,2));
    retorno.setValue(2,1,-getValue(0,0)*getValue(1,2)+getValue(1,0)*getValue(0,2));
    retorno.setValue(2,2,getValue(0,0)*getValue(1,1)-getValue(1,0)*getValue(0,1));

    return retorno;
}
