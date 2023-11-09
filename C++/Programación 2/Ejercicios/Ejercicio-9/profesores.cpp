#include "profesores.h"

Profesores::Profesores()
{

}

string Profesores::getNombre() const
{
    return nombre;
}

void Profesores::setNombre(const string &value)
{
    if(value.size() == 0){
            throw string {"No has introducido nombre"};
        }
    nombre = value;
}

string Profesores::getCorreo() const
{
    return correo;
}

void Profesores::setCorreo(const string &value)
{
    if(value.size() == 0){
            throw string {"No has introducido correo"};
        }
    correo = value;
}

string Profesores::getAsignaturas() const
{
    return asignaturas;
}

void Profesores::setAsignaturas(const string &value)
{
    if(value.size() == 0){
            throw string {"No has introducido asignaturas"};
        }
    asignaturas = value;
}
