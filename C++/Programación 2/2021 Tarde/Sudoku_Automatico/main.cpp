#include <iostream>
#include <fstream>
#include <array>

#include "sudoku.h"

using namespace std;

int main()
{
    Sudoku sudoku;

    if(sudoku.leerArchivo(sudoku)) cout << "Sudoku que se quiere resolver: \n" << sudoku << endl;

    if(sudoku.resolverSudoku(sudoku, 0, 0)) cout << "El sudoku resuelto es: \n" << sudoku;
    else cout << "No hay solucion" << endl;


}
