#ifndef ALUMNOS_H
#define ALUMNOS_H
#include <iostream>
using namespace std;



class Alumnos
{
    friend ostream & operator <<(ostream & os, Alumnos & a1);
public:
    Alumnos();
    Alumnos(string _nombre, string _correo, string _asignaturas);

    string getNombre() const;
    void setNombre(const string &value);

    string getCorreo() const;
    void setCorreo(const string &value);

    string getAsignutas() const;
    void setAsignutas(const string &value);

private:
    string nombre;
    string correo;
    string asignutas;
};

#endif // ALUMNOS_H
