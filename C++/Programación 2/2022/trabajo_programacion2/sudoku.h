#ifndef SUDOKU_H
#define SUDOKU_H
#include "tablero.h"
#include <array>

using namespace std;

class Sudoku : public Tablero // La clase Sudoku hereda de la clase Tablero
{
    // Atributo en la clase Tablero
public:
    Sudoku();

    bool numeroEnColumna(int columna, int num); // Devuelve verdadero si hay un numero en una columna
    bool numeroEnFila(int fila, int num); // Devuelve verdadero si hay un numero en una columna
    bool lugarVacio(int &fila, int &columna); // Devuelve verdadero si encuentra una posición vacía
    bool lugarValido(int fila, int columna, int num); // Devuelve verdadero cuando no se encuentra numero en columna y fila
    bool resolverSudoku(); // Devuelve verdadero si se puede imprimir el sudoku resuelto

    void printSudoku();
};

#endif // SUDOKU_H
