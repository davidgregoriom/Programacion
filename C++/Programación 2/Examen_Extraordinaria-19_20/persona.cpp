#include "persona.h"
//realizado por Carmen Sánchez

Persona::Persona(string name, string DNI){ //constructor
    setName(name);
    setDNI(DNI);
}

string Persona::getName() const{
    return name;
}

void Persona::setName(const string &value){
    name = value;
}

string Persona::getDNI() const{
    return dni;
}

void Persona::setDNI(const string &value){
    if(value.length() != 9) throw string {"DNI con una longitud incorrecta"};
    dni = value;
}

//sobrecarga del operador <<
ostream &operator <<(ostream os, Persona &P){
    os << "Name " << P.getName() << "\n";
    os << "DNI " << P.getDNI() << "\n";
    return os;
}
