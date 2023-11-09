#ifndef PROFESORES_H
#define PROFESORES_H
#include <iostream>
using namespace std;


class Profesores
{
public:
    Profesores();

    string getNombre() const;
    void setNombre(const string &value);

    string getCorreo() const;
    void setCorreo(const string &value);

    string getAsignaturas() const;
    void setAsignaturas(const string &value);

private:
    string nombre;
    string correo;
    string asignaturas;

};

#endif // PROFESORES_H
