#include "cuadrado.h"
#include "figura.h"

Cuadrado::Cuadrado()
{

}

Cuadrado::Cuadrado(float lado):ellado{lado}{}

float Cuadrado::getArea()
{
    return area;
}

float Cuadrado::getPerímetro()
{
    return ellado*4;
}
