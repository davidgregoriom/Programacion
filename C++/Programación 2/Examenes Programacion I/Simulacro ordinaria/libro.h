#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <string>
using namespace std;

class Libro
{

public:
    Libro();
    Libro(string _autor, string _titulo, string _tags, string _ubicacion, int _indice);

    string getAutor() const;
    void setAutor( string value);

    string getTitulo() const;
    void setTitulo(string value);

    string getTags() const;
    void setTags( string value);

    string getUbicacion() const;
    void setUbicacion( string value);

    int getIndice() const;
    void setIndice( int value);

    bool esEste(string _autor, string _titulo, string _tags, string _ubicacion, int _indice);
    void print() const;

private:
    string autor;
    string titulo;
    string tags;
    string ubicacion;
    int indice;
};

#endif // LIBRO_H
