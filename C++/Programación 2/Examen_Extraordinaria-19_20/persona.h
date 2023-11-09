#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

#include <ostream>

//realizado por Carmen Sánchez
using namespace std;

class Persona{
public:

    Persona(string name, string DNI); //constructor

    string getName() const;
    void setName(const string &value);

    string getDNI() const;
    void setDNI(const string &value);

private:

    string name;
    string dni;

};

//sobrecarga del operador <<
ostream &operator <<(ostream os, Persona &P);

#endif // PERSONA_H
