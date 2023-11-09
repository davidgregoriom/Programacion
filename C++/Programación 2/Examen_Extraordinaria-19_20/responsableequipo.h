#ifndef RESPONSABLEEQUIPO_H
#define RESPONSABLEEQUIPO_H

#include <iostream>

#include <vector>

#include "empleados.h"
//realizado por Carmen Sánchez

using namespace std;

class ResponsableEquipo: public Empleados{
public:

    ResponsableEquipo(vector<string> tareas); //constructor

    string getName() const;
    void setName(const string &value);

    string getDNI() const;
    void setDNI(const string &value);

    void tareas(string descripcion, bool realizacion, int num);
    void tarjetas(string descripcion, int listado, string el_responsable, string tipo);

    void printinforma() const;

};

//sobrecarga del operador <<
ostream &operator<<(ostream os, ResponsableEquipo &RE);


#endif // RESPONSABLEEQUIPO_H
