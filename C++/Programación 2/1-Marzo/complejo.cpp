#include "complejo.h"
#include <iostream>
#include <math.h>

using namespace  std;

void Complejo::add(Complejo&  other){
   real=real+other.real;
   imaginaria=imaginaria+other.imaginaria;
}

void Complejo::setReal(float value)
{
    real = value;
}

void Complejo::setImaginaria(float value)
{
    imaginaria = value;
}

Complejo::Complejo(float real, float imaginaria):real{real},imaginaria{imaginaria}
{

}

Complejo::Complejo()
{
    real=0;
    imaginaria=0;
}

void Complejo::print() const
{
    cout<<real<<"+"<<imaginaria<<"\n";
}

float Complejo::module() const
{
    float resultado;
    resultado=sqrt((real*real)+(imaginaria*imaginaria));
    return resultado;
}

float Complejo::getReal() const
{
    return real;
}

float Complejo::getImag() const
{
    return imaginaria;
}
