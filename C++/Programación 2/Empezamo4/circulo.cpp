#include "circulo.h"

Circulo::Circulo()
{

}

float Circulo::getArea() const
{
    return 3,14 * radio*radio;
}

float Circulo::getLongitud() const
{
   return 3,14 * radio;
}

float Circulo::getRadio() const
{
    return radio;
}

void Circulo::setRadio(float value)
{
    if(radio >0)radio  = value;
    else radio =0;
}
