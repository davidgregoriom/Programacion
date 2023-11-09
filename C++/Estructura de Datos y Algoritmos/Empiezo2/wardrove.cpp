#include "wardrove.h"
#include <memory>
using namespace std;
#include <iostream>

wardrove::wardrove()
{

}
int wardrobe::size() const
{
    std::shared_ptr <wardrobelement> iterator = front;
      int posElemento = 0;
      while (iterator !=  nullptr){
          iterator = iterator -> next;
          posElemento++;
      }
      return posElemento;
}

bool Wardrobe::empty() const
{
    if(size() ==0)return true;
    else return false;
}

void Wardrobe::wardrobe(Wardrobe &joy_slava, Wardrobe &men, Wardrobe &women)
{

}

void Wardrobe::push(const std::string &dato)
{
    auto elem = std::make_shared<WardrobeElement>(WardrobeElement{dato});
        if (front != nullptr) {
            elem->next = front;
            front = elem;
        }
        else {
            front = elem;
        }
}

void Wardrobe::pop()
{
    if (front != nullptr) {
            front = front->next;
        }
        std::cout << front;
}
