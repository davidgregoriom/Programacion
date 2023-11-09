#include "articulo.h"

Articulo::Articulo()
{

}

string Articulo::getOtros_autores() const
{
    return otros_autores;
}

void Articulo::setOtros_autores(const string &value)
{
    otros_autores = value;
}
