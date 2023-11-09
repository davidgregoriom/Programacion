#include <iostream>
#include "persona.h"
#include <string>

Persona::Persona (int edadUsuario, bool edadPosibleUsuario) {
    edad = edadUsuario;

    if (edadUsuario < 1 || edadUsuario > 110) {
        throw std::string {"Esta edad es imposible\n"};
        edadPosibleUsuario = false;
    }
    else {
        throw std::string {"Esta edad es posible"};
        edadPosibleUsuario = true;
    }
}
