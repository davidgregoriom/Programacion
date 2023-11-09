#include "trabajadores.h"

//realizado por Carmen Sánchez

void Trabajadores::tarjetas(string descripcion, int listado, string el_responsable, string tipo){
    cout << "¿Que tipo de tarea es? " << descripcion << "\n";
    cout << "¿Quien es el responsable de la realizacion de esta tarea? " << el_responsable << "\n";
    cout << "¿De que tipo es esta tarea? " << tipo << "\n";
    cout << "¿Quiere un listado con todas las tareas? " << listado << "\n";
}

void Trabajadores::printinforma() const{
    cout << "My name is " << getName() << "\n";
    cout << "My DNI is " << getDNI() << "\n";
}

//sobrecarga del operador <<
ostream &operator<<(ostream os, Trabajadores &T){
    os << "Name " << T.getName() << "\n";
    os << "DNI " << T.getDNI() << "\n";
    return os;
}
