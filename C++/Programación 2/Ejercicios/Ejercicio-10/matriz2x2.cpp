#include "matriz2x2.h"

Matriz2x2::Matriz2x2():matrizGeneral(2,2)
{//Constructor que llama a constructor de clase de la que hereda

}

double Matriz2x2::getDeterminant()
{
    return getValue(0,0)*getValue(1,1)-getValue(1,0)*getValue(0,1);
}
Matriz2x2 Matriz2x2::getInverse()
{
    Matriz2x2 retorno;
    int cols=getNcols();
    int fils=getNfils();

    if(getDeterminant()==0)
    {
        throw std::string{"no invertible"};
    }
    else
    {
        Matriz2x2 aux1=getTraspose();
        Matriz2x2 aux2=aux1.getAdjugate();

        try{
            double det=getDeterminant();
            for(int f{0};f<fils;f++)
            {
                for(int c{0};c<cols;c++)
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

Matriz2x2 Matriz2x2::getTraspose()
{
    Matriz2x2 retorno;
    int cols=getNcols();
    int fils=getNfils();

    for(int i{0};i<fils;i++)
    {
        for(int j{0};j<cols;j++)
        {
            retorno.setValue(i,j,getValue(j,i));
        }
    }

    return retorno;
}

Matriz2x2 Matriz2x2::getAdjugate()
{
    Matriz2x2 retorno;

    retorno.setValue(0,0,getValue(1,1));
    retorno.setValue(0,1,-getValue(1,0));
    retorno.setValue(1,0,-getValue(0,1));
    retorno.setValue(1,1,getValue(0,0));

    return retorno;
}
