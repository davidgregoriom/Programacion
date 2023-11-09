
#ifndef ARTICULO_H
#define ARTICULO_H
#include "publicacion.h"
#include <iostream>

using namespace std;

class Articulo:public Publicacion
{
private:
    string otros_autores;
public:
    Articulo(const string &titulo, const string &autor,const string &otros_autores):Publicacion(titulo,autor){
        setOtros_autores(otros_autores);
    }
    string getOtros_autores() const{
        return otros_autores;
    }
    void setOtros_autores(const string &value){
        if(value.size()==0) throw string {"no amigo"};
        otros_autores=value;
    }
    string WhoAmI()const{
        return ("Articulo");
    }
};

#endif // ARTICULO_H
