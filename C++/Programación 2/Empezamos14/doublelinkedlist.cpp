#include "doublelinkedlist.h"
#include "elementolistadoble.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList()
{

}

void DoubleLinkedList::for_each(std::function<void (TipoDato &)> action) const
{
     shared_ptr<ElementoListaDoble> iterator = next;
        while (iterator != nullptr) {
            action(iterator->dato);
            iterator = iterator->next;
        }
}

void DoubleLinkedList::for_each_reverse(std::function<void (TipoDato &)> action) const
{
    shared_ptr<ElementoListaDoble> iterator = prev;
       while (iterator != nullptr) {
           action(iterator->dato);
           iterator = iterator->next;
       }
}

int DoubleLinkedList::size() const
{
    std::shared_ptr <ElementoListaDoble> iterator = front;
      int posElemento = 0;
      while (iterator !=  nullptr){
          iterator = iterator -> next;
          posElemento++;
      }
      return posElemento;
}

bool DoubleLinkedList::empty() const
{
    if(size() ==0)return true;
    else return false;
}

void DoubleLinkedList::push_back(const TipoDato &dato)
{
        std::shared_ptr<ElementoListaDoble> elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
        if (empty(ElementoListaDoble)) {
             = elem;
        }
        else {
            std::shared_ptr<ElementoListaDoble> iterator = lista;
            while (iterator->next != ) {
                iterator = iterator->next;
            }
            iterator->next = elem;
        }
}

void DoubleLinkedList::push_front(const TipoDato &dato)
{
    std::shared_ptr<ElementoListaDoble> elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if (empty(ElementoListaDoble)) {
        ElementoListaDoble = elem;
    }
    else {
        elem->next = ElementoListaDoble;
        ElementoListaDoble = elem;
    }
}


