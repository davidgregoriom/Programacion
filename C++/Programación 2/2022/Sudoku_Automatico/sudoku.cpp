#include <iostream>
#include <vector>
#include <fstream>
#include "sudoku.h"

using namespace std;

Sudoku::Sudoku(array<array<int, 9>, 9> datos): Tablero(datos){

}

Sudoku::Sudoku():Tablero(datos)
{

}
bool Sudoku::numeroEnColumna(Sudoku const &sudoku, int columna, int num)
{
    for(int f = 0; f< 9; f++) {
        if(sudoku.datos[f][columna] == num) return false;
    }
    return true;
}

bool Sudoku::numeroEnFila(Sudoku const &sudoku, int fila, int num)
{
    for(int c = 0; c < 9; c++) {
        if(sudoku.datos[fila][c] == num) return false;
    }
    return true;
}

bool Sudoku::numeroEnCuadrado3x3(Sudoku const &sudoku, int fila, int columna, int num)
{
    int numFila = fila - (fila % 3);
    int numCol = columna - (columna % 3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku.datos[numFila + i][numCol + j] == num) return false;
        }
    }
    return true;
}

bool Sudoku::lugarVacio(Sudoku const &sudoku,int &fila, int &columna)
{
    for(fila = 0; fila < 9; fila++) {
        for(columna = 0; columna < 9; columna++) {
            if(sudoku.datos[fila][columna] == 0) return true;
        }
    }
    return false;
}

bool Sudoku::lugarSeguro(Sudoku const &sudoku, int fila, int columna, int num)
{
    numeroEnFila(sudoku, fila, num);
    numeroEnColumna(sudoku, fila, num);
    numeroEnCuadrado3x3(sudoku, fila, columna, num);
}

bool Sudoku::asignar(Sudoku &sudoku, int fila, int columna,int numero){
    if(numeroEnCuadrado3x3(sudoku,fila,columna,numero)==false || numeroEnFila(sudoku,fila,numero)==false || numeroEnColumna(sudoku,columna,numero)==false){
        return false;
    }else if(numeroEnCuadrado3x3(sudoku,fila,columna,numero)==true && numeroEnFila(sudoku,fila,numero)==true && numeroEnColumna(sudoku,columna,numero)==true && lugarVacio(sudoku,fila,columna)==true){
        sudoku.datos[fila][columna]=numero;
        return true;
    }

}

bool Sudoku::resolverSudoku(Sudoku &sudoku, int fila, int columna)
{
    if(fila == 9 ){
        return true;
    }
    if(columna == 9) {
        fila++;
        columna = 0;
    }

    if(sudoku.datos[fila][columna] > 0) {
        if( resolverSudoku(sudoku, fila, columna + 1)){
            return true;
        }
    }

    for(int i = 1; i <= 9; i++) {
        if(lugarSeguro(sudoku, fila, columna, i)) {
            if(asignar(sudoku,fila,columna,i)==true){
                   if(resolverSudoku(sudoku, fila, columna + 1)) return true;

            }
        }
        sudoku.datos[fila][columna] = 0;
    }
    return false;
}


bool Sudoku::leerArchivo(Sudoku &sudoku)
{
    cout << "Introduzca la ruta del archivo donde esta guardado el sudoku: " << endl;
    string ruta; getline(cin, ruta); //C:\\Users\\zorri\\Desktop\\trabajo_programacion2\\sudoku.txt
    ifstream filename(ruta);
    bool esLegible = filename.is_open();
    if(!esLegible) cout << "No se puede leer el archivo" << endl;
    else {
        for(int fila = 0; fila < 9; fila++) {
            for(int col = 0; col < 9; col++) {
                filename >> sudoku.datos[fila][col];
            }
        }
    }
    return esLegible;
}





ostream &operator<<(ostream &os, const Sudoku &sudoku)
{
    int fila, col;
    for(fila = 0; fila < 9; fila++) {
        for(col = 0; col < 9; col++) {
            if(col == 3 || col == 6) cout << "| ";

            os << sudoku.datos[fila][col] << " ";
        }
        cout << endl;
        if(fila == 2 || fila == 5) {
            for(int i = 0; i < 7; i++) {
                cout << "---";
            }
            cout << endl;
        }
    }
    return os;
}

