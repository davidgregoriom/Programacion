#include <iostream>
#include "biblioteca.h"
using namespace std;

int main()
{
    Biblioteca biblio;

    string autor, titulo, tags, ubicacion;
    int indice;
    Libro aux;
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
    return 0;

}
