#ifndef NUMERO_COMPLEJO_H
#define NUMERO_COMPLEJO_H


class Numero_Complejo
{
public:
    Numero_Complejo(float a,float b): a{a},b{b}{}
    float getA() const;
    void setA(float value);

    float getB() const;
    void setB(float value);

private:
    float a,b;

};

#endif // NUMERO_COMPLEJO_H
