#ifndef ELEMENTOARBOLBINARIO_H
#define ELEMENTOARBOLBINARIO_H
#include <memory>
#include "empleado.h"

class ElementoArbolBinario
{
public:
        // Members
        Empleado dato;
        std::shared_ptr<ElementoArbolBinario> left = nullptr;
        std::shared_ptr<ElementoArbolBinario> right = nullptr;
    public:
        // Constructor
        ElementoArbolBinario(const Empleado& dato_);

};

#endif // ELEMENTOARBOLBINARIO_H
