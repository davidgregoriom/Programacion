#include<iostream>
#include "cuadrado.h"
#include "circulo.h"

using namespace std;

int main(){
    Cuadrado miCuadrado;
    ///miCuadrado.lado= 5; Nunca se hace así.
    miCuadrado.setlado(5);
    cout << miCuadrado.getArea() << "\n";
    cout << miCuadrado.getPerimetro() << "\n";

    miCuadrado.print();
    Circulo miCirculo;
    miCirculo.setRadio(12);

    cout << miCirculo.getArea() << "\n";
}
