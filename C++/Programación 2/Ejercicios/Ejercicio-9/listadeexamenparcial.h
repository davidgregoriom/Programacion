#ifndef LISTADEEXAMENPARCIAL_H
#define LISTADEEXAMENPARCIAL_H

#include <iostream>

using namespace std;

template<typename N,typename C, typename A>
class Persona
{
    template<typename fN,typename  fC, typename fA> friend ostream & operator <<(ostream,Persona <fN,fC,fA> const &p);
public:
    Persona(N const& n,C const& c, A const&a);
    N name();
    C corr();
    A signature();

private:
    N Nombre;
    C Correo;
    A Asignatura;
};

template<typename N, typename C, typename A>
Persona<N,C,A>::Persona(const N &n, const C &c, const A &a)
{
 Nombre= n;
 Correo = c;
 Asignatura= a;
}

template<typename N, typename C, typename A>
N Persona<N,C,A>::name()
{
 return Nombre;
}

template<typename N, typename C, typename A>
C Persona<N,C,A>::corr()
{
 return Correo;
}

template<typename N, typename C, typename A>
A Persona<N,C,A>::signature()
{
 return Asignatura;
}

template<typename N, typename C, typename A>
ostream &operator <<(ostream & os,  Persona<N,C,A> const &p)
{
 os << p.Nombre <<p.Correo << p.Asignatura;
 return os;
}
#endif // LISTADEEXAMENPARCIAL_H
