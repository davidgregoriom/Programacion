#include <memory>
#include <iostream>

struct TipoDato {}; // Any datatype: int, std::string, float,...

class Element { // Also known as Node sometimes
    public:
        // Members
        TipoDato dato;
        std::shared_ptr<Element> next = nullptr;
    public:
        // Constructor
        Element(const TipoDato& dato_) : dato{dato_} {};
};
