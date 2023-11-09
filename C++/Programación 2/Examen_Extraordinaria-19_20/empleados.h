#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include <iostream>

#include "persona.h"
//realizado por Carmen Sánchez
using namespace std;

class Empleados: public Persona{
public:

    Empleados(); //constructor

    string getName() const;
    void setName(const string &value);

    string getDNI() const;
    void setDNI(const string &value);

};

//sobrecarga del operador <<
ostream &operator<<(ostream os, Empleados &E);

#endif // EMPLEADOS_H
