#include <iostream>
//#include "matrizgeneral.h"
#include "matriz2x2.h"
#include "matriz3x3.h"
#include "matrizdiagonal.h"

using namespace std;

int main()
{
    cout << "matriz 2x2" << endl;

    Matriz2x2 miMatriz;

    miMatriz.setValue(0,0,1);
    miMatriz.setValue(0,1,2);
    miMatriz.setValue(1,0,-2);
    miMatriz.setValue(1,1,3);

    miMatriz.mostrar();

    std::cout<<miMatriz.getDeterminant()<<std::endl;

    auto adj=miMatriz.getAdjugate();
    auto tr=miMatriz.getTraspose();
    auto inv=miMatriz.getInverse();

    adj.mostrar();
    tr.mostrar();
    inv.mostrar();

    cout << "matriz diagonal" << endl;

    MatrizDiagonal miMatrizDiag(3);

    miMatrizDiag.setValue(0,0,1);
    miMatrizDiag.setValue(1,1,2);
    miMatrizDiag.setValue(2,2,3);

    miMatrizDiag.mostrar();

    auto adjDiag=miMatrizDiag.getAdjugate();
    auto trDiag=miMatrizDiag.getTraspose();
    auto invDiag=miMatrizDiag.getInverse();

    adjDiag.mostrar();
    trDiag.mostrar();
    invDiag.mostrar();

    cout << "matriz 3x3" << endl;

    Matriz3x3 miMatriz3;

    miMatriz3.setValue(0,0,4);
    miMatriz3.setValue(0,1,0);
    miMatriz3.setValue(0,2,0);
    miMatriz3.setValue(1,0,0);
    miMatriz3.setValue(1,1,0);
    miMatriz3.setValue(1,2,-2);
    miMatriz3.setValue(2,0,1);
    miMatriz3.setValue(2,1,-2);
    miMatriz3.setValue(2,2,4);

    miMatriz3.mostrar();

    auto adj3=miMatriz3.getAdjugate();
    auto tr3=miMatriz3.getTraspose();
    auto inv3=miMatriz3.getInverse();

    adj3.mostrar();
    tr3.mostrar();
    inv3.mostrar();

    cout << "matriz general 2x1" << endl;

    matrizGeneral miMatrizGen(2,1);

    miMatrizGen.setValue(0,0,1);
    miMatrizGen.setValue(1,0,2);

    miMatrizGen.mostrar();

    return 0;
}
