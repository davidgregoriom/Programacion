#include "wardrove.h"
#include <memory>
using namespace std;
#include <iostream>
#include "elementoslistadoble.h"
#include "queue.h"



Wardrobe::Wardrobe()
{

}

int Wardrobe::size() const
{
    std::shared_ptr <WardrobeElement> iterator = front;
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

void wardrobe(Queue &joy_slava, Wardrobe &men, Wardrobe &women)
{
    shared_ptr <ElementListaDoble> iterator =  joy_slava.getback();
    while(iterator != nullptr){
        if((iterator->dato).get_gender() == 0){
            men.push((iterator->dato).get_name());
        }else{
            women.push((iterator->dato).get_name());
        }
    }

    iterator = iterator->prev;
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
