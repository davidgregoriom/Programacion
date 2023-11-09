#ifndef WARDROVE_H
#define WARDROVE_H
#include <iostream>
#include <memory>
#include "wardrovelement.h"

class wardrove
{
public:
       wardrobe();

       int size() const;
       bool empty() const;

       void wardrobe(wardrobe & joy_slava, wardrobe & men, wardrobe & women);

       void push(const std::string& dato);
       void pop();
       std::string& top() const;
   protected:
       std::shared_ptr<wardrovelement> front = nullptr;
};

#endif // WARDROVE_H
