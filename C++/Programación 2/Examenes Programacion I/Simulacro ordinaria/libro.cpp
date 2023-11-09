#include "libro.h"

Libro::Libro()
{

}

Libro::Libro(string _autor, string _titulo, string _tags, string _ubicacion, int _indice)
{
    if(!(_tags == "matematicas"||_tags == "primaria"||_tags == "operaciones")){
        throw string {"Tags incorrectos"};
    }
    if(_indice <= 0){
        throw string {"El numero tiene que ser positivo"};
    }

    autor = _autor;
    titulo = _titulo;
    tags = _tags;
    ubicacion = _ubicacion;
    indice = _indice;
}

string Libro::getAutor() const
{
    return autor;
}

void Libro::setAutor( string value)
{
    autor = value;
}

string Libro::getTitulo() const
{
    return titulo;
}

void Libro::setTitulo( string value)
{
    titulo = value;
}

string Libro::getTags() const
{
    return tags;
}

void Libro::setTags( string value)
{
    tags = value;
}

string Libro::getUbicacion() const
{
    return ubicacion;
}

void Libro::setUbicacion( string value)
{
    ubicacion = value;
}

int Libro::getIndice() const
{
    return indice;
}

void Libro::setIndice( int value)
{
    indice = value;
}

bool Libro::esEste(string _autor, string _titulo, string _tags, string _ubicacion, int _indice)
{
    return ((_autor == autor) && (_titulo == titulo) && (_tags == tags) && (_ubicacion == ubicacion) && (_indice == indice));
}

void Libro::print() const
{
    cout << "Autor: " << autor << endl;
    cout << "Titulo del Libro: " << titulo << endl;
    cout << "Tag: " << tags << endl;
    cout << "Ubicacion del libro: " << ubicacion << endl;
    cout << "Indice: " << indice << endl;
}
