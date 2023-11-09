#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <vector>
#include <memory>
#include "libro.h"
using namespace std;

class Biblioteca
{
    friend ostream & operator <<(ostream & os, Biblioteca & b1);
public:
    Biblioteca();

    bool nuevoLibro(string _autor, string _titulo, string _tags, string _ubicacion, int _indice);
    bool eliminarLibro(string _autor, string _titulo, string _tags, string _ubicacion, int _indice);
    bool modificarLibro(int indice_, string _autor, string _titulo, string _tags, string _ubicacion);
    bool buscarLibro(string _autor, string _titulo, string _tags, string _ubicacion, int _indice, Libro & libro);

    vector<Libro> getBiblioteca() const;
    void setBiblioteca(const vector<Libro> &value);

private:
    vector<Libro> biblioteca;
};

#endif // BIBLIOTECA_H
