#ifndef COLEGIO_H
#define COLEGIO_H
#include <iostream>
#include <string>

using namespace  std;
class Colegio
{
public:
    Colegio();
    string nombre;
    int nota;
    string getNombre() const;
    void setNombre(const string &value);

    int getNota() const;
    void setNota(int value);

    int getNumero_examenes_realizados1() const;
    void setNumero_examenes_realizados1(int value);

private:
    int numero_examenes_realizados1;
};

#endif // COLEGIO_H
