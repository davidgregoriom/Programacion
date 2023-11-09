#include <iostream>
#include "sudoku.h"

using namespace std;

Sudoku::Sudoku()
{

}

bool Sudoku::numeroEnColumna(int columna, int num)
{
    for(int fila = 0; fila < datos.size(); fila++) {
        if(datos.at(fila).at(columna) == num) return true;
    }
    return false;
}

bool Sudoku::numeroEnFila(int fila, int num)
{
    for(int columna = 0; columna < datos.size(); columna++) {
        if(datos.at(fila).at(columna) == num) return true;
    }
    return false;
}

bool Sudoku::lugarVacio(int &fila, int &columna)
{
    for(fila = 0; fila < datos.size(); fila++) {
        for(columna = 0; columna < datos.size(); columna++) {
            if(datos.at(fila).at(columna) == 0) return true;
        }
    }
    return false;
}

bool Sudoku::lugarValido(int fila, int columna, int num)
{
    return (!numeroEnFila(fila, num) && !numeroEnColumna(columna, num));
}

bool Sudoku::resolverSudoku()
{
    int fila, columna;
    if(!lugarVacio(fila, columna)) return true; // Devuelve verdadero si no queda ningún espacio vacío, todo está lleno
    for(int num = 1; num <= 9; num++) { // Dígitos válidos -> 1 al 9
        if(lugarValido(fila, columna, num)) {
            datos.at(fila).at(columna) = num;
            if(resolverSudoku()) return true;
            datos.at(fila).at(columna);
        }
    }
    return false;
}

void Sudoku::printSudoku()
{

}
