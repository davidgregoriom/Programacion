#include <iostream>
#include "printer.h"
#include "printjob.h"

using namespace std;

int main()
{


    ifstream is("Home/Desktop/Estructura de Datos Y Algoritmos/Untitled Document 1");
    string linea;
    while(getline(is,linea)){
        cout << linea <<endl;
    }

}
