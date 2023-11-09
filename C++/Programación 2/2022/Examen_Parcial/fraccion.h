#ifndef FRACCION_H
#define FRACCION_H

#include <cmath>

class Fraccion
{
private:
    int numerador,denominador;


    void simplificar()
    {//Método para simplificar la fracción encapsulada en la clase
         //int r = MaxComDiv(numerador,denominador);
         int r = MCD(numerador,denominador);
         numerador=numerador/r; //simplificamos numerador
         denominador=denominador/r; //simplificamos denominador
    }

    int MaxComDiv(int a,int b)
    {//Método para calcular el máximo comun divisor

        a=abs(a);
        b=abs(b);
        while (a != b)
        {//Mientras sean distintos
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
        return a;
    }

    int MCD(int x, int y)
    {//Versión recursiva del Máximo Comun Divisor
        if(y==0)
        {//Condición fin recursividad
            return x;
        }
        else
        {
            return MCD(y, x%y);//Llamada recursiva
        }
    }
public:
    Fraccion(){denominador=1;numerador=0;}
    Fraccion(int num,int den)
    {
        setDenominador(den); //Utilizo los setter para controlar la definición de número racional
        setNumerador(num);  //Si no al crear el objeto puedo crear una fracción fuera de la definición...
    }
    Fraccion(const Fraccion &f){
        this->denominador=f.getDenominador();
        this->numerador=f.getNumerador();
    }

    void setNumerador(int n){
        numerador=n;
    }
    void setDenominador(int d){
        if(d<0)
        {
            denominador=-d;
            throw 1;
        }
        else if(d==0)
        {
            denominador=1;
            throw 0;
        }
        denominador=d;
    }

    int getNumerador(void) const{
        return numerador;
    }

    int getDenominador(void)const{
        return denominador;
    }

    Fraccion operator +(const Fraccion &operando)
    {
        Fraccion aux;
        aux.setDenominador(denominador*operando.getDenominador());
        aux.setNumerador(numerador*operando.getDenominador()+denominador*operando.getNumerador());

        aux.simplificar();
        return aux;
    }

    Fraccion operator -(const Fraccion &operando)
    {
        Fraccion aux;
        aux.setDenominador(denominador*operando.getDenominador());
        aux.setNumerador(numerador*operando.getDenominador()-denominador*operando.getNumerador());

        aux.simplificar();
        return aux;
    }

    Fraccion operator *(const Fraccion &operando)
    {
        Fraccion aux;
        aux.setDenominador(denominador*operando.getDenominador());
        aux.setNumerador(numerador*operando.getNumerador());

        aux.simplificar();
        return aux;
    }

    Fraccion simplificar(const Fraccion& f)
    {//Simplifica una fracción pasada por parametro
        Fraccion aux=f;
        aux.simplificar();
        return aux;
    }

};
#endif // FRACCION_H
