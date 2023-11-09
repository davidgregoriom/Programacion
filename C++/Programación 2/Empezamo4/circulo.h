#ifndef CIRCULO_H
#define CIRCULO_H


class Circulo
{
public:
    Circulo();
    float getArea() const;
    float getLongitud() const;
    float getRadio() const;
    void setRadio(float value);

private:
    float radio;

};

#endif // CIRCULO_H
