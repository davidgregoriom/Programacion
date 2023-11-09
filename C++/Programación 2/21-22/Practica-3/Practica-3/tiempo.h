#ifndef TIEMPO_H
#define TIEMPO_H
#include <iostream>

using namespace std;

class Tiempo
{
    friend istream & operator >>(istream &is, Tiempo &a);
    friend ostream & operator <<(ostream &os, Tiempo const & b);
    friend bool operator ==( Tiempo const & c, Tiempo const & d);
    friend Tiempo operator +(Tiempo const & e, Tiempo const & f);
    friend Tiempo operator -(Tiempo const & g, Tiempo const & h);
public:
    Tiempo();
    Tiempo(Tiempo const & other);
    Tiempo(int h,int m, int s);
    int getH() const;
    void setH(int value);

    int getM() const;
    void setM(int value);

    int getS() const;
    void setS(int value);

    int TiempoSegundos(int s2);
private:
    int h,m,s;
};

#endif // TIEMPO_H
