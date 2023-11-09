#ifndef SUDOKU_H
#define SUDOKU_H
#include "tablero.h"
#include <array>
#include <ostream>
#include <memory>

using namespace std;

class Sudoku : public Tablero // La clase Sudoku hereda de la clase Tablero
{
    // Atributo en la clase Tablero

public:
    Sudoku(array<array<int, 9>, 9> datos);
    Sudoku();

    bool numeroEnColumna(Sudoku const &sudoku, int columna, int num);
    bool numeroEnFila(Sudoku const &sudoku, int fila, int num);
    bool numeroEnCuadrado3x3(Sudoku const &sudoku, int fila, int columna, int num);

    bool asignar(Sudoku  &sudoku, int fila, int columna,int numero);
    bool lugarSeguro(Sudoku const &sudoku, int fila, int columna, int num);
    bool resolverSudoku(Sudoku &sudoku, int fila, int columna);
    bool lugarVacio(Sudoku const &Sudoku,int &fila, int &columna);

    bool leerArchivo(Sudoku &sudoku);
    friend ostream& operator<< (ostream& os, const Sudoku& sudoku);


};
#endif // SUDOKU_H
