#include <iostream>

using namespace std;

int cambio(int p){
    int vecesRepetidas = 0;

    while(p>=100){
        vecesRepetidas++;
        p = p-100;
    }

    cout <<  vecesRepetidas << " de 100 \n";
    vecesRepetidas = 0;
    while(p>=50){
        vecesRepetidas++;
        p = p-50;
    }

    cout << vecesRepetidas << " de 50 \n";
    vecesRepetidas=0;
    while(p>=25){
        vecesRepetidas++;
        p = p-25;
    }

    cout <<  vecesRepetidas << " de 25 \n";
    vecesRepetidas = 0;
    while(p>=5){
        vecesRepetidas++;
        p = p - 5;
    }

    cout <<  vecesRepetidas << " de 5 \n";
    vecesRepetidas = 0;
    while(p>=2){
        vecesRepetidas++;
        p = p - 2;
    }

    cout <<  vecesRepetidas << " de 2 \n";
    vecesRepetidas = 0;
    while(p>=1){
        vecesRepetidas++;
        p = p - 1;
    }

    cout <<  vecesRepetidas << " de 1 \n";
    vecesRepetidas = 0;

    return p;

}

int main()
{
  string devolverString = "2.53";
  string nuevoString = "";
  int num1;
  int tamano = 0;
   while (devolverString.size() > tamano) {

     if (devolverString.at(tamano) == '.') {

     }
     else {
       nuevoString = nuevoString + devolverString.at(tamano);
     }

     tamano++;
   }

  num1 = stoi(nuevoString);
    cout << "String: " << nuevoString << "\n";

    cout<< cambio(num1);
}
