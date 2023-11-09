#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <memory>
#include <array>
#include <string>

using namespace std;

struct TipoDato{string dato;};
/*
class recorrido
{
public:
    recorrido(int salida, int llegada);
    int getSalida() const;
    void setSalida(int value);

    int getLlegada() const;
    void setLlegada(int value);




private:
    int salida;
    int llegada;

};

*/
class ElementoListaDoble {
public:

TipoDato dato;
std::shared_ptr<ElementoListaDoble> next = nullptr;
std::shared_ptr<ElementoListaDoble> prev = nullptr;
public:

ElementoListaDoble(const TipoDato & dato_);
};


#endif // RECORRIDO_H
