#ifndef ELEMENTOARBOLBINARIO_H
#define ELEMENTOARBOLBINARIO_H
#include <iostream>
#include <memory>
#include "hashtags.h"

class ElementoArbolBinario
{
public:
        // Members
        hashtags dato;
        std::shared_ptr<ElementoArbolBinario> left = nullptr;
        std::shared_ptr<ElementoArbolBinario> right = nullptr;
    public:
        // Constructor
        ElementoArbolBinario(const hashtags& dato_) ;
};
struct ElementoQueue {
   ElementoArbolBinario dato;
   std::shared_ptr<ElementoQueue> next = nullptr;
};

class Queue {
     public:
         Queue() {}
         bool empty() const { return _front == nullptr;}

         ElementoArbolBinario& front() const { return _front->dato; }

         void pop() {
             _front = _front->next;
         }

     protected:
         std::shared_ptr<ElementoQueue> _front = nullptr;
         std::shared_ptr<ElementoQueue> _back = nullptr;
};

#endif // ELEMENTOARBOLBINARIO_H
