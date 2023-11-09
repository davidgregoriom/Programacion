#include "biblioteca.h"

vector<shared_ptr<Publicacion> > Biblioteca::getBiblio() const
{
    return biblio;
}

void Biblioteca::setBiblio(const vector<shared_ptr<Publicacion> > &value)
{
    biblio = value;
}

Biblioteca::Biblioteca()
{

}

vector<shared_ptr<Publicacion> > Biblioteca::getBiblio() const
{
    return biblio;
}
