#include "publicacion.h"

Publicacion::Publicacion()
{

}

string Publicacion::getAutor() const
{
    return autor;
}

void Publicacion::setAutor(const string &value)
{
    autor = value;
}

string Publicacion::getTitulo() const
{
    return titulo;
}

void Publicacion::setTitulo(const string &value)
{
    titulo = value;
}
