#include "tiempo.h"
#include <iostream>
using namespace std;


Tiempo::Tiempo(): h{0},m{0},s{0}{}

Tiempo::Tiempo(Tiempo const&other)
{
    h,m,s = other.h,m,s;
}

Tiempo::Tiempo(int h, int m, int s): h{h},m{m},s{s}{}


int Tiempo::getH() const
{
    return h;
}

void Tiempo::setH(int value)
{
    h = value;
}

int Tiempo::getM() const
{
    return m;
}

void Tiempo::setM(int value)
{
    if(value>59){
     throw string{"Error"};
     value = m-60;
     h++;
    }else{
        m=value;
    }

}

int Tiempo::getS() const
{
    return s;
}

void Tiempo::setS(int value)
{
    if(value>59){
     throw string{"Error"};
     value = s-60;
     m++;

    }else{
        s=value;
    }
}

int Tiempo::TiempoSegundos(int s2)
{
   s2 = h*60+m*60+s;
   return s2;
}

istream &operator >>(istream &is, Tiempo &t)
{
    int a,b,c;
    is>> a >> b >> c;
    t.setH(a);
    t.setM(b);
    t.setS(c);
    return is;
}

ostream &operator <<(ostream &os, const Tiempo &b)
{
    os << "Las horas son:"<< b.h << "  los minutos:"<< b.m << "  los segundos"<< b.s << "del objeto."<< "\n";
    return os;
}

bool operator ==(const Tiempo &c, const Tiempo &d)
{
    if(c.h==d.h && c.m==d.m && c.s==d.s)return true;
    else return false;
}

Tiempo operator +(const Tiempo &e, const Tiempo &f)
{
    Tiempo result(e.h+f.h,e.m+f.m,e.s+f.s);
    return result;
}

Tiempo operator -(const Tiempo &g, const Tiempo &h)
{
    Tiempo result(g.h-h.h,g.m-h.m,g.s-h.s);
    return result;
}
