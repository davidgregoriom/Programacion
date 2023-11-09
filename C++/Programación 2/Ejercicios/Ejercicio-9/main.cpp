#include <memory>
#include <iostream>
#include "lista.h"
#include "pesona.h"

using namespace std;
using std::shared_ptr;
using std::make_shared;


int main()
{

    string nombre, correo, asignaturas;
    bool condicion = true;
    int opcion;

    Lista<shared_ptr<Persona>> alumnos;
    Lista<shared_ptr<Persona>> prefesores;

    while(condicion == true){
        cout << "1. Añadir alumno: " << endl;
        cout << "2. Añadir profesor: " << endl;
        cout << "3. Mostrar alumnos y profesores: " << endl;
        cout << "4. Buscar alumno por correo electronico: " << endl;
        cout << "5. MOstrar todos los alumnos por una asignatura en concreta: " << endl;
        cout << "6. Buscar por nombre: " << endl;
        cout << "7. salir" << endl;

        cin >> opcion;

        while(opcion < 1||opcion >  7){
            cout << "Accion no valida eliga la correcta" << endl;
            cin >> opcion;
        }
        cout << endl;

        switch (opcion) {
            case 1:
            std::cout<<"Introduzca el Nombre del contacto to add:";
            cin>>nombre;
            std::cout<<"Introduzca el correo del contacto to add:";
            cin>>correo;
            std::cout<<"Introduzca el asignaturas del contacto to add:";
            cin>>asignaturas;

            try {
            auto alumno = make_shared<Persona>(nombre, correo, asignaturas);
            alumnos.insertar(alumno);

        }  catch (string e) {
            cout << e << endl;
        }
            break;
        case 2:
            std::cout<<"Introduzca el Nombre del contacto to add:";
            cin>>nombre;
            std::cout<<"Introduzca el correo del contacto to add:";
            cin>>correo;
            std::cout<<"Introduzca el asignaturas del contacto to add:";
            cin>>asignaturas;

            try {
            auto profesor = make_shared<Persona>(nombre, correo, asignaturas);
            prefesores.insertar(profesor);

        }  catch (string e) {
            cout << e << endl;
        }
            break;
        case 3:
            cout << "Lista de alumnos: " << endl;
            cout << alumnos << endl;
            cout << "Lista de profesores " << endl;
            cout << prefesores << endl;

        case 7:
            condicion = false;
            break;

         }

    }

    cout << "Adiosss" << endl;

    return 0;
}




