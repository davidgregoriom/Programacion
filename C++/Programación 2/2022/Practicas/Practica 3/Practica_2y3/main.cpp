#include <iostream>
#include "tipos.h"
#include "fila.h"
#include "fila2.h"

using namespace std;

int main()
{
    Persona p{"Julia Perez",31},p1{"Pepe Perez",30},p2{"Toni Martin",21},p3{"Ana Martinez",27},p4{"Federico",18};


    std::cout<<"Pruebas con lista doblemente enlazada..."<<std::endl;
    fila2 dobleEnlace;

    dobleEnlace.push(p);dobleEnlace.push(p1);dobleEnlace.push(p2);

    cout<<dobleEnlace.pop()<<endl; //Se marcha uno del doble enlace y lo mostramos por terminal

    cout<<dobleEnlace<<endl;

    cout<<"Terminando...";


    return 0;
}
