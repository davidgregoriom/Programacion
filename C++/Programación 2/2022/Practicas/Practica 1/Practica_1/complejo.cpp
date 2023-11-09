#include "complejo.h"

Complejo::Complejo()
{//Constructor por defecto
    pReal=0;
    pImag=0;
}

Complejo::Complejo(double a, double b)
{//Constructor con parámetros
    pReal=a;
    pImag=b;
};
Complejo::Complejo(const Complejo& c)
{//Constructor por copia
    pReal=c.pReal;
    pImag=c.pImag;
};

//Getters y setters
double Complejo::getPImag() const
{
    return pImag;
}

void Complejo::setPImag(double value)
{
    pImag = value;
}

double Complejo::getPReal() const
{
    return pReal;
}

void Complejo::setPReal(double value)
{
    pReal = value;
}

//Operaciones
Complejo Complejo::sumar(const Complejo& C)
{
    Complejo aux;
    aux.setPReal(pReal+C.pReal);
    aux.setPImag(pImag+C.pImag); //Como somos Complejo podemos acceder con el . al igual que el constructor copia

    return aux;
};

double Complejo:: modulo()
{
    return sqrt(pow(pReal,2)+pow(pImag,2));
};

Complejo Complejo::dividir(const Complejo& C)
{
    Complejo aux;
    //https://www.superprof.es/diccionario/matematicas/aritmetica/division-complejos.html
    if( (pow(C.pReal,2)+pow(C.pImag,2))!=0)
    {// Caso sin error
        //Según la fórmula de la división de números complejos tendremos el error DIV/0 cuando el denominador sea 0
        //Antes de que ocurra ese error lo comprobamos
        aux.setPReal((pReal*C.pReal+pImag*C.pImag)/(pow(C.pReal,2)+pow(C.pImag,2)));
        aux.setPImag((pImag*C.pReal-pReal*C.pImag)/(pow(C.pReal,2)+pow(C.pImag,2)));
    }
    else
    {//Tenemos error div/0 -> Lanzamos excepción
        throw std::string{"Error div/0"};
    }

    return aux;
};

//Visualización
void Complejo::imprimir()
{
    if(pImag>=0)
    {
        std::cout<<pReal<<"+"<<pImag<<"*j"<<std::endl;
    }
    else
    {
        std::cout<<pReal<<pImag<<"*j"<<std::endl;
    }
};
