#include "publicacion.h"

vector<shared_ptr<publicacion> > publicacion::getPublicado() const
{
    return publicado;
}

/*void publicacion::añadir(const vector<shared_ptr<publicacion> > &value)
{
    publicado.push_back(value);
}
*/
