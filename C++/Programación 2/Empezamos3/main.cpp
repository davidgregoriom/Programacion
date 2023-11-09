#include <iostream>

using namespace std;

class Cuadrado{
public:
    float getArea();
    float getPerimetro();
    void setlado(float l);
    void print();

private:
    float lado;
};
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


int main(){
    Cuadrado miCuadrado;
    ///miCuadrado.lado= 5; Nunca se hace así.
    miCuadrado.setlado(5);
    cout << miCuadrado.getArea() << "\n";
    cout << miCuadrado.getPerimetro() << "\n";

    miCuadrado.print();

}
