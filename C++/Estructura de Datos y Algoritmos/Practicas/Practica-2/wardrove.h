#ifndef WARDROVE_H
#define WARDROVE_H
#include <iostream>
#include <memory>
#include "wardrovelement.h"
#include "elementoslistadoble.h"
#include "queue.h"

class Wardrobe {
    public:
        Wardrobe();

        int size() const;
        bool empty() const;


        void push(const std::string& dato);
        void pop();
        std::string& top() const;
    protected:
        std::shared_ptr<WardrobeElement> front = nullptr;
};
void wardrobe(Queue& joy_slava, Wardrobe& men, Wardrobe& women);
#endif // WARDROVE_H
