#ifndef FIGURAS_H
#define FIGURAS_H

#include <iostream>
using namespace std;
#include <math.h>


class figuras
{
public:
    figuras();

    virtual float computeArea() = 0;
    virtual float computePerimetro() = 0;
};

class circulo : public figuras
{
public:
    circulo(const float  r): r{r}
    {

    }
    float computeArea(){
        cout << 3.14*r*r;
    }
    float computePerimetro(){
        cout << 2*3.14*r;
    }
protected:
    float r;
};


class cuadrado: public figuras
{
public:
    cuadrado();
    float computeArea(){
        cout << l*l;
    }
    float computePerimetro(){
        cout << l*4;
    }
protected:
    float l;

};


class triangulo : public figuras
{
public:
    triangulo();
    float computeArea(){
    cout << l*l/2;
    }
    float computePerimetro(){
        cout << l*3;
    }

protected:
    float l;
};


class pentagono: public figuras
{
public:
    pentagono();
    float computeArea(){
     cout <<(l*l/2)*5;
    }
    float computePerimetro(){
        cout << l*5;
    }

protected:
     float l;
};


class elipse: public figuras
{
public:
    elipse();
    float computeArea(){

    }
    float computePerimetro(){

    }

protected:
    float l;
};
#endif // FIGURAS_H
