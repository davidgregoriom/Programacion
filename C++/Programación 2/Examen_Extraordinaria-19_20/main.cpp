#include <iostream>

#include "persona.h"
#include "empleados.h"
#include "responsableequipo.h"
#include "trabajadores.h"
//realizado por Carmen Sánchez
using namespace std;

int main(){

    string persona;
    string empleado;
    string trabajador;
    string responsable_equipo;
    string tarjeta;
    string tipo;

    string name;
    string DNI;

    int option{9};

    while(option != 0){
        cout << "¿Que quieres hacer?" << "\n";
        cout << "1. ¿Quieres incorporar una nueva tarjeta? " << "\n";
        cout << "2. ¿De que tipo quiere la tarjeta? " << "\n";
        cout << "3. Nombre y DNI por favor " << "\n";
        cout << "4. Listado " << "\n";
        cout << "0. Salir " << "\n";
        cin >> option;

        if(option == 1){
            cout << "Tarjeta: ";
            cin >> tarjeta;
        }
        if(option == 2){
            cout << "Tipo de Tarjeta: ";
            cin >> tipo;
        }
        if(option == 3){
            cout << "Nombre: ";
            cin >> name;
            cout << "DNI: ";
            cin >> DNI;
        }
        if(option == 4){
            cout << " _____ " << "\n\n";
            cout << "Lista: " << "\n";
            for(auto empleados: empleado){
                cout << responsable_equipo;
                cout << trabajador;

                cout << " ----- " << "\n\n";
            }
            cout << " _____ " << "\n\n";
        }
    }

    return 0;

}
