#ifndef LISTA_H
#define LISTA_H
#include "hashtags.h"
#include <string>

struct tweet{string tweets;};

class ElementListaSimple {
    public:
        // Members
        tweet dato;
        std::shared_ptr<ElementListaSimple> next = nullptr;
    public:
        // Constructor
        ElementListaSimple(const tweet& dato_) : dato{dato_} {}
};

class lista
{
public:
    lista(tweet &datos);
    void push_back(const hashtags& dato);

protected:
    std::shared_ptr<ElementListaSimple> front = nullptr;

};

#endif // LISTA_H
