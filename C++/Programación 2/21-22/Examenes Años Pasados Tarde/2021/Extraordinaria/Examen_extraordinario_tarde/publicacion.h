

#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <iostream>
#include "biblioteca.h"

using namespace std;

class Publicacion
{
private:
    string titulo,autor;
public:
    Publicacion(const string &titulo,const string &autor){
        setAutor(autor);
        setTitulo(titulo);
    }
    string getTitulo() const{
        return titulo;
    }
    void setTitulo(const string &value){
        if(value.size()==0) throw string {"no amigo"};
        titulo=value;
    }

    string getAutor() const{
        return autor;
    }
    void setAutor(const string &value){
        if(value.size()==0) throw string {"no amigo"};
        autor=value;
    }
    virtual string WhoAmI()const=0;
};

#endif // PUBLICACION_H
