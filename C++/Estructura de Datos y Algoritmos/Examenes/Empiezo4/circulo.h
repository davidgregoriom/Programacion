#ifndef CIRCULO_H
#define CIRCULO_H
#include "figura.h"



class circulo:public figura
{
public:
    circulo();
    void setarea();
    void setvolumen();
private:
    float radio;
};

#endif // CIRCULO_H
