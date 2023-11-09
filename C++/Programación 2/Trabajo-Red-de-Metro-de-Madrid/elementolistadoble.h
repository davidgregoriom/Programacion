#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include <iostream>
#include <memory>

using namespace std;

struct TipoDato{string dato;};

class ElementoListaDoble {
public:

TipoDato dato;
std::shared_ptr<ElementoListaDoble> next = nullptr;
std::shared_ptr<ElementoListaDoble> prev = nullptr;
public:

ElementoListaDoble(const TipoDato & dato_);
};
#endif // ELEMENTOLISTADOBLE_H
