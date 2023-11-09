#ifndef TRABAJADORES_H
#define TRABAJADORES_H

#include <iostream>

#include "empleados.h"

using namespace std;
//realizado por Carmen Sánchez


class Trabajadores: public Empleados{
public:

    Trabajadores(string departamento); //constructor

    string getName() const;
    void setName(const string &value);

    string getDNI() const;
    void setDNI(const string &value);

    void tareas(string descripcion, bool realizacion, int num);
    void tarjetas(string descripcion, int listado, string el_responsable, string tipo);

    void printinforma() const;

};

//sobrecarga del operador <<
ostream &operator<<(ostream os, Trabajadores &T);

#endif // TRABAJADORES_H
