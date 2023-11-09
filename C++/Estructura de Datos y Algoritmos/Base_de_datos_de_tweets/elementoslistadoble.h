#ifndef ELEMENTOSLISTADOBLE_H
#define ELEMENTOSLISTADOBLE_H


#pragma once

#include <memory>
#include "filter.h"

class ElementArbolDoble {
    public:
        // Members
        hashtags dato;
        std::shared_ptr<ElementArbolDoble> next = nullptr;
        std::shared_ptr<ElementArbolDoble> prev = nullptr;
    public:
        // Constructor
        ElementArbolDoble(const hashtags& dato_);
};

#endif // ELEMENTOSLISTADOBLE_H
