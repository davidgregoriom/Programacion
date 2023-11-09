#include <iostream>
#include <fstream>
#include <vector>

#include "sudoku.h"

using namespace std;

int main()
{
    string filename("Sudoku.cpp"); // No consigo que lea el archivo "Sudoku", q se halla en Other files
    vector<string> lineas;
    string linea;

    ifstream archivo(filename);
    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << filename << endl;
        return EXIT_FAILURE;
    }

    while(getline(archivo, linea)) lineas.push_back(linea);

    for(auto &elem: lineas) {
        cout << elem << endl;
    }

    archivo.close();
    return EXIT_SUCCESS;

    /*Sudoku sudoku;

    if(sudoku.resolverSudoku() == true) sudoku.printSudoku();
    else cout << "No existe solucion" << endl;*/
}
