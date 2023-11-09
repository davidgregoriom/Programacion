#ifndef PESONA_H
#define PESONA_H

#include <memory>
#include <iostream>
#include <string>

using std::shared_ptr;
using std::make_shared;

using namespace std;

class Persona{
public:
    Persona(string name, string correo, string asignaturas): name{name}, correo{correo}, asignaturas{asignaturas}{};

    string getName() const;
    void setName(const string &value);

    string getCorreo() const;
    void setCorreo(const string &value);

    string getAsignaturas() const;
    void setAsignaturas(const string &value);

private:

    string name;
    string correo;
    string asignaturas;
};
std::ostream &operator<<(ostream &os, shared_ptr<Persona>& p);


#endif // PESONA_H
