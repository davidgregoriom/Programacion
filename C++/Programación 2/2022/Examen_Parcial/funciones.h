#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <vector>
#include <memory>
#include "fraccion.h"

std::ostream& operator <<(std::ostream &os, const Fraccion &f)
{
    if(f.getDenominador()!=1)
    {//Si el denominador es distinto de 1 mostramos como fracción...
        os<<f.getNumerador()<<"/"<<f.getDenominador()<<std::endl;
    }
    else
    {//Si es 1 mostramos el numerador unicamente...
        os<<f.getNumerador();
    }
    return os;
}

std::istream& operator >>(std::istream &i, Fraccion &f)
{
    int n,d;
    std::cout<<"Introduce numerador y denominador separados por un espacio"<<std::endl;
    i>>n>>d;

    f.setNumerador(n);
    f.setDenominador(d);

    return i;
}

std::ostream& operator<<(std::ostream &os, const std::vector<std::shared_ptr<Fraccion>> &vec)
{
    os<<"El historico es: ";
    for(auto e:vec)
    {//recorremos el vector de punteros mostrando su contenido
      //Como el contenido es una fracción podemos usar la sobrecarga de << para Fraccion
        os<<*e<<"; ";
    }
    os<<std::endl;

    return os;
}


int menu(void)
{
    int aux{0};
    std::cout<<"Menu*********"<<std::endl;
    std::cout<<"0.- Salir"<<std::endl;
    std::cout<<"1.- Introducir 2 fracciones en memoria"<<std::endl;
    std::cout<<"2.- Sumar"<<std::endl;
    std::cout<<"3.- Restar"<<std::endl;
    std::cout<<"4.- Multiplicar"<<std::endl;
    std::cout<<"5.- Visualizar fracciones en memoria"<<std::endl;
    std::cin>>aux;
    if(aux<0 or aux>5)
    {
        return -1;
    }
    return aux;
}

#endif // FUNCIONES_H
