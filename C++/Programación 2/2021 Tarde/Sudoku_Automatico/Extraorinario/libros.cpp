#include "libros.h"

libros::libros(const string &titulo_, const string &autor_, const string &editorial_)
{
    if(titulo_.empty()||autor_.empty()||editorial_.empty()){
        throw("aqui hay elementos si poner");
    }
    titulo=titulo_;
    autor=autor_;
    editorial=editorial_;

}
