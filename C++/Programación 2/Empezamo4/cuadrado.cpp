#include "cuadrado.h"
#include <iostream>


using namespace  std;
void Cuadrado::print(){

       cout << "EL cuadrado del lado es " << lado << "\n";
       cout << "area:"<< getArea() << "\n";
       cout << "Perímetro" << getPerimetro() << "\n";
}



void Cuadrado::setlado(float l){
    if(l <0) lado =0;
    else lado = l;
}


float Cuadrado::getArea(){
    return lado*lado;
}

float Cuadrado::getPerimetro(){
    return 4*lado;
}
