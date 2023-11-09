#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <memory>
#include "complejo.h"

int menu()
{
    int opcion{0};
    std::cout<<"Menu calculadora Complejos\n";
    std::cout<<"1.- Introducir 2 complejos\n";
    std::cout<<"2.- Sumar 2 complejos\n";
    std::cout<<"3.- Modulo\n";
    std::cout<<"4.- Division\n";
    std::cout<<"5.- Salir\n";

    std::cout<<"Opcion?"<<std::endl;
    std::cin>>opcion;
    if(opcion<6 or opcion>0)
    {
        return opcion;
    }
    else
    {
        return -1;
    }
}

void MostrarHistorico(const std::vector<std::shared_ptr<Complejo>>& Cs,const std::vector<std::shared_ptr<double>>& Ms)
{
    std::cout<<"Historico 1: "<<std::endl;
    for(auto elem:Cs)
    {
        elem->imprimir(); //Cada elem es un puntero a Complejo. Con el operador -> accedemos a sus miembros (atributos y métodos)
    }

    std::cout<<"Historico 2: "<<std::endl;
    for(auto elem:Ms)
    {
        std::cout<<*elem<<std::endl; //Cada elem es un puntero a double. Con el operador *desreferenciamos y accedemos al contenido
    }
}

Complejo IntroducirComplejoTerminal()
{
    float auxReal,auxImag;

    std::cout<<"Parte real...?"<<std::endl;
    std::cin>>auxReal;
    std::cout<<"Parte imaginaria...?"<<std::endl;
    std::cin>>auxImag;

    return Complejo(auxReal,auxImag);
}

#endif // FUNCIONES_H
