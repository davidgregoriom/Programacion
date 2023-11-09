#include <iostream>
#include <string>
#include "persona.h"


int main() {
    bool valorCorrecto = false;
    int edad = 0;


    while (valorCorrecto == false) {

        if (valorCorrecto == false) {
            try {
                std::cout << "Introduce una edad: ";
                std::cin >> edad;
                Persona a (edad, valorCorrecto);
            }

            catch (std::string e){
                std::cout << e << "\n";
            }

            if (edad > 0 || edad >= 110) {
                valorCorrecto = true;
            }

        }

    }
}
