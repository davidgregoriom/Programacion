#include "tipodato.h"
#include <iostream>
using namespace std;
tipodato::tipodato()
{

}

tipodato::tipodato(string asignatura, float horas_a_la_semana, bool Como_la_llevo)
{

}

ostream & operator<<(ostream & os,tipodato const & j)
{
    os <<"La asignatura es:"<< j.asignatura <<endl << "el numero de horas empleadas ha sido:" << j.horas_a_la_semana << endl << "y si realmente lo llevo para aprobar:" << j.Como_la_llevo<< endl;
    return os;
}
