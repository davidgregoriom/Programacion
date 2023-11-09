#include "biblioteca.h"

Biblioteca::Biblioteca()
{

}

bool Biblioteca::nuevoLibro(string _autor, string _titulo, string _tags, string _ubicacion, int _indice)
{
    Libro libro;
    if(!buscarLibro( _autor,  _titulo,  _tags,  _ubicacion,  _indice, libro)){
        Libro libro{_autor, _titulo, _tags, _ubicacion, _indice};
        biblioteca.push_back(libro);
        return true;
    }
    return false;
}

bool Biblioteca::eliminarLibro(string _autor, string _titulo, string _tags, string _ubicacion, int _indice)
{
    for(int i=0; i < biblioteca.size(); i++){
        if(biblioteca.at(i).esEste(_autor, _titulo, _tags, _ubicacion, _indice)){
            biblioteca.erase(biblioteca.begin()+i);
            return true;
        }
    }
    return false;
}

bool Biblioteca::modificarLibro(int indice_, string _autor, string _titulo, string _tags, string _ubicacion)
{
    for(auto aux: biblioteca){
        if(aux.getIndice() == indice_){
            aux.setAutor(_autor);
            aux.setTitulo(_titulo);
            aux.setTags(_tags);
            aux.setUbicacion(_ubicacion);
            return true;
        }
    }
    return false;

}

bool Biblioteca::buscarLibro(string _autor, string _titulo, string _tags, string _ubicacion, int _indice, Libro & libro)
{
    for(auto  aux: biblioteca){
        if(aux.esEste(_autor, _titulo, _tags, _ubicacion, _indice)){
            libro = aux;
            return true;
        }
    }
    return false;
}

vector<Libro> Biblioteca::getBiblioteca() const
{
    return biblioteca;
}

void Biblioteca::setBiblioteca(const vector<Libro> &value)
{
    biblioteca = value;
}

ostream & operator <<(ostream & os, Biblioteca & b1){

}







