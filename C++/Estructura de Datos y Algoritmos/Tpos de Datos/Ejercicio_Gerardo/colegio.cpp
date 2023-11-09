#include "colegio.h"

Colegio::Colegio()
{
    nombre ="maria";
    nota =0;
    numero_examenes_realizados1 =50;

}

int Colegio::getNota() const
{
    return nota;
}

void Colegio::setNota(int value)
{
    nota = value;
}

int Colegio::getNumero_examenes_realizados1() const
{
    return numero_examenes_realizados1;
}

void Colegio::setNumero_examenes_realizados1(int value)
{
    numero_examenes_realizados1 = value;
}

string Colegio::getNombre() const
{
    return nombre;
}

void Colegio::setNombre(const string &value)
{
    nombre = value;
}
