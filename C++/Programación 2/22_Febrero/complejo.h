#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <string>
#include <iostream>
using namespace std;



class Complejo
{
private:
    float a;
    float b;
public:
    Complejo();
    Complejo(float a , float b);
    float modulo();
    float getA() ;
    void setA(float value);
    float getB() ;
    void setB(float value);
};

#endif // COMPLEJO_H
