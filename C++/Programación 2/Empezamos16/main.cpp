#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <memory>
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
    if(value.size() <=0) throw string {"no hay libros"};
    biblioteca = value;
}

ostream & operator <<(ostream & os, Biblioteca & b1){

}







int main()
{
    Biblioteca biblio;

    string autor, titulo, tags, ubicacion;
    int indice;
    Libro aux;

    try{
        int opcion = 1;



        while(opcion >=0 ){
            switch (opcion) {
            case 0:
                return 0;
            case 1:
                cout << "0. salir " << endl;
                cout << "2.Añadir libro " << endl;
                cout << "3.Buscar libro por tags, titulo y autor " << endl;

                cout << "Introduce opcion " << endl;
                cin >> opcion;
                break;
            case 2:
                cout << "Introduce autor: "; cin >> autor;
                cout << "Introduce titulo: "; cin >> titulo;
                cout << "Introduce tags: "; cin >> tags;
                cout << "Introduce ubicacion: "; cin >> ubicacion;
                cout << "Introduce indice: "; cin >> indice;
                if(biblio.nuevoLibro(autor, titulo, tags, ubicacion, indice)){
                    cout << "Libro añadido correctamente." << endl;
                }else{
                    cout << "Se ha añadido mal." << endl;
                }
                opcion = 1;
                break;
            case 3:
                cout << "Introduce autor: "; cin >> autor;
                cout << "Introduce titulo: "; cin >> titulo;
                cout << "Introduce tag: "; cin >> tags;
                if(biblio.buscarLibro(autor, titulo, tags, ubicacion, indice, aux)){
                    cout << "libro encontrado" << endl;
                    aux.print();

                    cout << "Que quieres hacer: " << endl;
                    cout << "4. Listar libros " << endl;
                    cout << "5. Modificar lrbos por indice " << endl;
                    cout << "6. ELiminar libros " << endl;
                    cout << "0. salir " << endl;
                    cin >> opcion;
                }else{
                    cout << "No se ha encontrado el libro" << endl;
                    opcion = 1;
                }
                break;
            case 4:
                cout << biblio;
            case 5:
                cout << "Introduce indice a buscar: " << endl;
                cin >> indice;

                if(indice == biblio.buscarLibro(autor, titulo, tags, ubicacion, indice, aux)){
                    cout << "Introduce autor: "; cin >> autor;
                    cout << "Introduce titulo: "; cin >> titulo;
                    cout << "Introduce tags: "; cin >> tags;
                    cout << "Introduce ubicacion: "; cin >> ubicacion;
                    biblio.modificarLibro(indice, autor, titulo, tags, ubicacion);
                    cout << "Modificacion realizada con exito" << endl;
                }else{
                    cout << "Fallo en la modificacion" << endl;
                }
                opcion = 1;
                break;
            case 6:
                if(biblio.eliminarLibro(autor, titulo, tags, ubicacion, indice)){
                    cout << "Contacto eliminador correctacmete" << endl;
                }else{
                    cout << "No se ha eliminador bien" << endl;
                }
                opcion = 1;
                break;
            default:
                opcion = 0;
            }
        }
    }catch(string e){
        cout  << e << "\n";
    }
    cout << "Adiosss\n";
    return 0;

}
