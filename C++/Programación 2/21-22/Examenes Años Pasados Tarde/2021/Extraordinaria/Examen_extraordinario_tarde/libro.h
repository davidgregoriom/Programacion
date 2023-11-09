#ifndef LIBRO_H
#define LIBRO_H
#include "publicacion.h"
#include <iostream>
using namespace std;

class Libro:public Publicacion
{
private:
    string editorial;
public:
    Libro(const string &titulo, const string &autor,const string &editorial):Publicacion(titulo,autor){
        setEditorial(editorial);
    }
    string getEditorial() const{
        return editorial;
    }
    void setEditorial(const string &value){
        if(value.size()==0) throw string {"no amigo"};
        editorial=value;
    }
    string WhoAmI()const{
        return ("Libro");
    }
};

#endif // LIBRO_H
