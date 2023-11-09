#include "responsableequipo.h"
//realizado por Carmen Sánchez

void ResponsableEquipo::tareas(string descripcion, bool realizacion, int num){
    cout << "¿Que numero de tarea es? " << num << "\n";
    cout << "¿Que tipo de tarea es? " << descripcion << "\n";
    cout << "Dicha tarea, ¿esta hecha o sin terminar? " << realizacion << "\n";
}

void ResponsableEquipo::printinforma() const{
    cout << "My name is " << getName() << "\n";
    cout << "My DNI is " << getDNI() << "\n";
}

//sobrecarga del operador <<
ostream &operator<<(ostream os, ResponsableEquipo &RE){
    os << "Name " << RE.getName() << "\n";
    os << "DNI " << RE.getDNI() << "\n";
    return os;

}
