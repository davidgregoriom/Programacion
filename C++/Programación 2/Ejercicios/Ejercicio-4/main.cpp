#include <iostream>
#include "matrix.h"


int main()
{
    try{
        std::cout << "Introduce el numero de filas y columnas de la matriz 1: ";
        int fil, cols;
        std::cin >> fil >> cols;
        Matrix mat1{fil, cols};
        std::cout << "Introduce la matriz, numero a numero, por filas:\n";
        std::cin >> mat1;

        std::cout << "Introduce el numero de filas y columnas de la matriz 2: ";

        std::cin >> fil >> cols;
        Matrix mat2{fil, cols};
        std::cout << "Introduce la matriz, numero a numero, por filas:\n";
        std::cin >> mat2;

        Matrix suma = mat1 + mat2;
        Matrix resta = mat1 - mat2;
        Matrix mult = mat1 * mat2;
        std::cout << "Suma\n" << suma << "\n\n";
        std::cout << "Resta\n" << resta << "\n\n";
        std::cout << "Multiplicación\n" << mult << "\n\n";

    }catch(std::string e){
        std::cout << e << "\n";
    }

    return 0;
}
