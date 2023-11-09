#ifndef ELEMENTOSLISTADOBLE_H
#define ELEMENTOSLISTADOBLE_H


#pragma once

#include <memory>
#include "persona.h"

class ElementListaDoble {
    public:
        // Members
        Persona dato;
        std::shared_ptr<ElementListaDoble> next = nullptr;
        std::shared_ptr<ElementListaDoble> prev = nullptr;
    public:
        // Constructor
        ElementListaDoble(const Persona& dato_);
};

#endif // ELEMENTOSLISTADOBLE_H
