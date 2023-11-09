#ifndef COLLECTIONS_H
#define COLLECTIONS_H
#pragma once

#include <memory>
#include <functional>
#include "binarytree.h"
using namespace std;

using TipoDato = std::string;

class ElementListaSimple {
    public:
        // Members
        TipoDato dato;
        std::shared_ptr<ElementListaSimple> next = nullptr;
    public:
        // Constructor
        ElementListaSimple(const TipoDato& dato_) : dato{dato_} {}
};


// Una lista simple enlazada
class LinkedList {
    public:
        LinkedList();

        void push_back(const TipoDato& dato) {
            auto elem = std::make_shared<ElementListaSimple>(ElementListaSimple{dato});
            if (front == nullptr) {
                front = elem;
            }
            else {
                auto iterator = front;
                while (iterator->next != nullptr) {
                    iterator = iterator->next;
                }
                iterator->next = elem;
            }
        }

        void for_each(std::function<void (const TipoDato&)> action) {
            auto iterator = front;
            while (iterator != nullptr) {
                action(iterator->dato);
                iterator = iterator->next;
            }
        }

    protected:
        std::shared_ptr<ElementListaSimple> front = nullptr;
};


// Una pila
class Stack {
    public:
        Stack();

        int size() const;
        bool empty() const;

        void push(const TipoDato& dato);
        void pop() const;
        TipoDato& top() const;
    protected:
        std::shared_ptr<ElementListaSimple> front = nullptr;
};


#endif // COLLECTIONS_H
