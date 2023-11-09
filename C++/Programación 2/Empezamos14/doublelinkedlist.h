#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "elementolistadoble.h"
#include <functional>
#include <memory>
using namespace std;

class DoubleLinkedList {
    public:
        DoubleLinkedList();

        // Iterate forward
        void for_each(std::function<void (TipoDato&)> action) const;

        // Iterate backward
        void for_each_reverse(std::function<void (TipoDato&)> action) const;

        // Size-related methods
        int size() const;
        bool empty() const;

        // Insertion
        void push_back(const TipoDato& dato);
        void push_front(const TipoDato& dato);

    private:
        std::shared_ptr<ElementoListaDoble> front = nullptr;
        std::shared_ptr<ElementoListaDoble> back = nullptr;
};

#endif // DOUBLELINKEDLIST_H
