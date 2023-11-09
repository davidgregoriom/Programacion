#include "pesona.h"

string Persona::getName() const
{
    return name;
}

void Persona::setName(const string &value)
{
    if(value.size() == 0){
        throw  string{"Introduce nombre"};
    }
    name = value;
}

string Persona::getCorreo() const
{
    return correo;
}

void Persona::setCorreo(const string &value)
{
    if(value.size() == 0){
        throw  string{"Introduce correo"};
    }
    correo = value;
}

string Persona::getAsignaturas() const
{
    return asignaturas;
}

void Persona::setAsignaturas(const string &value)
{
    if(value.size() == 0){
        throw  string{"Introduce asigntuas"};
    }
    asignaturas = value;
}
ostream &operator<<(ostream &os, shared_ptr<Persona>& p){
    os << "Nombre: " << p->getName() << endl;
    os << "Correo: " << p->getCorreo() << endl;
    os << "Asignaturas: " << p->getAsignaturas() << endl;
    return os;
}
