#include "complejo.h"
#include <iostream>
#include <cmath>

using namespace std;
float Complejo::getA()
{
    return a;
}

void Complejo::setA(float value)
{
    this -> a = value;
}

float Complejo::getB()
{
    return b;
}

void Complejo::setB(float value)
{
    this -> b = value;
}

Complejo::Complejo()
{
    a=0;
    b=0;
}

float Complejo::modulo()
{
    return ((a,2)+(b,2));
}

Complejo::Complejo(float na, float nb)
{
    a=na;
    b=nb;
}
