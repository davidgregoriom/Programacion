#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Complejo
{
private:
    float real;
    float imaginaria;
public:
    Complejo(float real,float imaginaria);
    Complejo();
    void print()const;
    float module()const;
    float getReal() const;
    float getImag() const;
    void setReal(float value);
    void setImaginaria(float value);
    void add(Complejo & other);
};

#endif // COMPLEJO_H
