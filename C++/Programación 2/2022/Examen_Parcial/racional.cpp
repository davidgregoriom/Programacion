include "racional.h"

racional::racional()
{
    numerador=0;
    denominador=0;
}

racional::racional(int numerador_, int denominador_)
{
    numerador_=numerador;
    denominador_=denominador;
}

racional::racional(const racional & a)
{
    numerador=a.numerador;
    denominador=a.denominador;
}

int racional::getNumerador() const
{
    return numerador;
}

void racional::setNumerador(int value)
{
    numerador = value;
}

int racional::getDenominador() const
{
    return denominador;
}

void racional::setDenominador(int value)
{
    if(value<0){
         denominador = value;
    }else{
        throw string{"valor erroneo"};
    }
}

 racional operator+(const racional &n, const racional &d)
{
    racional aux;


}

 racional operator-(const racional &n, const racional &d)
{

}

 racional  operator*(const racional &n, const racional &d)
{

}
