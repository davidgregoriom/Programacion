#include "articulos.h"

articulos::articulos(const string &titulo_, const string &autor_, const vector<string> &otros_autores_)
{
    if(titulo_.empty()||autor_.empty()||otros_autores_.empty()){
        throw("aqui hay elementos si poner");
    }
    titulo=titulo_;
    autor=autor_;
    otro_autores=otros_autores_;
}
