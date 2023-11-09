#include <iostream>

using namespace std;

class Cuadrilatero{
private:
    float lado1, lado2;
public:
    Cuadrilatero(float lado1,float lado2){//Constructor1
        this->lado1=lado1;
        this->lado2=lado2;
    }
    Cuadrilatero(float lado){//Constructor2
        this->lado1=this->lado2=lado;
    }
    float obternerPerimetro(){
        return 2*(lado1+lado2);
    }
    float obtenerArea(){
        return lado1*lado2;
    }
};

int main(){
    Cuadrilatero* c;
    float lado1,lado2;

    cout <<"Dime lado 1 y lado 2";
    cin >> lado1 >> lado2;

    if(lado1==lado2){
       c= new Cuadrilatero(lado1);
    }else{
        c=new Cuadrilatero(lado1,lado2);
    }
    cout << c->obtenerArea() << endl;
    cout << c->obternerPerimetro() << endl;
}


































































/*
class Persona{
private:
    string nombre ,dni;
    int edad;
public:
    Persona(const string & nombre, const int & edad){
        this->nombre=nombre;
        this->edad=edad;
    }
    Persona(const string & dni_){
        dni=dni_;
    }
    void correr(){
        cout << nombre << edad;
    }
    void correr(int & km){
        cout << km;
    }
};


int main(){
    int j=333;
    Persona * persona= new Persona("Alejandro",21);
    persona->correr(j);
    delete persona;
    cout << "Hello World!" << endl;
    return 0;
}
*/
