#include <memory>
#include <iostream>

using namespace std;

struct TipoDato {};

class ElementListaDoble {
    public:
        // Members
        TipoDato dato;
        std::shared_ptr<ElementListaDoble> next = nullptr;
        std::shared_ptr<ElementListaDoble> prev = nullptr;
    public:
        // Constructor
        ElementListaDoble(const TipoDato& dato_) : dato{dato_} {};
};
