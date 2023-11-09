#ifndef TIPODATO_H
#define TIPODATO_H
#include<iostream>
#include <string>

using namespace std;

class tipodato
{
public:
    tipodato();
    tipodato(string asignatura,float horas_a_la_semana,bool Como_la_llevo);



    friend ostream& operator<<(ostream & os,tipodato const & j);

private:
     string asignatura;
     float horas_a_la_semana;
     bool Como_la_llevo;

};

ostream& operator<<(ostream & os,tipodato const & j);
#endif // TIPODATO_H
