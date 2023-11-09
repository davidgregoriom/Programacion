#include "alumnos.h"

Alumnos::Alumnos()
{

}

Alumnos::Alumnos(string _nombre, string _correo, string _asignaturas)
{
    setNombre(_nombre);
    setCorreo(_correo);
    setAsignutas(_asignaturas);
}
string Alumnos::getNombre() const
{
    return nombre;
}

void Alumnos::setNombre(const string &value)
{
    if(value.size()==0) throw string{"No has introducid nombre"};
    nombre = value;
}

string Alumnos::getCorreo() const
{
    return correo;
}

void Alumnos::setCorreo(const string &value)
{
    if(value.size()==0) throw string{"No has introducid correo"};
    correo = value;
}

string Alumnos::getAsignutas() const
{
    return asignutas;
}

void Alumnos::setAsignutas(const string &value)
{
    if(value.size()==0) throw string{"No has introducid asignaturas"};
    asignutas = value;
}

ostream & operator <<(ostream & os, Alumnos & a1){
    os << "Nombre del alumno: " << a1.getNombre() << endl;
    os << "Correo del alumno: " << a1.getCorreo() << endl;
    os << "Asignaturas matriculadas del alumno: " << a1.getAsignutas() << endl;
    return os;
}
