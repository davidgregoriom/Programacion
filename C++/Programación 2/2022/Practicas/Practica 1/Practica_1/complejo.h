#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <cmath> //Para la raiz cuadrada y el módulo
#include <string> //Para la excepción
#include <iostream> //Para los cout

class Complejo{
    private:
        double pReal;
        double pImag;
    public:
        //Constructores
        Complejo();
        Complejo(double, double);
        Complejo(const Complejo&);

        double getPReal() const;
        void setPReal(double);
        double getPImag() const;
        void setPImag(double);

        //Operaciones
        Complejo sumar(const Complejo&);
        double modulo(void);
        Complejo dividir(const Complejo&);
        //Visualización
        void imprimir();
};

#endif // COMPLEJO_H
