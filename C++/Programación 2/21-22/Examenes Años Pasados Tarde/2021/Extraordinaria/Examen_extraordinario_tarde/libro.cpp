include "libro.h"

Libro::Libro()
{

}

string Libro::getEditorial() const
{
    return editorial;
}

void Libro::setEditorial(const string &value)
{
    editorial = value;
}
