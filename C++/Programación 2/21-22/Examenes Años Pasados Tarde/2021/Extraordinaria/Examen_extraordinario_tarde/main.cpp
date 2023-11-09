#include <iostream>
#include "biblioteca.h"

using namespace std;
int menu(){
    int op{0};
    std::cout<<"1.Añadir elemento a la biblioteca"<<std::endl;
    std::cout<<"2.Buscar un elemento"<<std::endl;
    std::cout<<"3.Borrar elementos"<<std::endl;
    std::cout<<"4.Mostrar un elemento"<<std::endl;
    std::cout<<"5.Mostrar elementos"<<std::endl;
    std::cout<<"Que quieres hacer?: ";
    std::cin>>op;cin.ignore();

    if(op>0 && op<6)
    {
        return op;
    }
    else
    {
        return -1;
    }
}


int main()
{
    Biblioteca biblio;
    bool continuar=true;
    int opcion=0,op=0;
    string titulo,autor,otros_autores,editorial;

    while(continuar){
        opcion=menu();
        switch(opcion){
        case 1:
            std::cout<<"Introduzca el Titulo:";
            cin>>titulo;
            std::cout<<"Introduzca el Autor:";
            cin>>autor;
            cout<< "que tipo de publicacion?: "<<endl;
            cout<< "¿Libro?Marque 1 "<<endl;
            cout<< "¿Articulo?Marque 2 "<<endl;
            cin>>op;
            if(op=1){
                cout<<"dime la editorial"<<endl;
                cin>>editorial;
                try {
                    auto libro = std::make_shared<Libro>(titulo,autor,editorial);
                    biblio.anadir(libro);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
            }else if(op=2){
                cout<<"dime el otro_autor"<<endl;
                cin>>otros_autores;
                try {
                    auto articulo = std::make_shared<Articulo>(titulo,autor,otros_autores);
                    biblio.anadir(articulo);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
            }else{
                cout<<"no lo has hecho bien "<<endl;
            }
            cin.ignore();
            break;
        case 2:
            std::cout<<"Introduzca el Titulo:";
            cin>>titulo;
            std::cout<<"Introduzca el Autor:";
            cin>>autor;
            biblio.buscar(titulo,autor);
            break;
        case 3:
            std::cout<<"Introduzca el Titulo:";
            cin>>titulo;
            std::cout<<"Introduzca el Autor:";
            cin>>autor;
            biblio.borrar(titulo,autor);
            break;
        case 4:

        case 5:
            cout<<biblio;

        default:
            cout<<"elige otra opcion "<< endl;
        }
        cout <<"¿Continuar?:[0->NO; 1->SI]";
        cin >>continuar;cin.ignore();
    }

    return 0;
}
