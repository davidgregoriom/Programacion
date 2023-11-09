#ifndef ELEMENTLISTASIMPLE_H
#define ELEMENTLISTASIMPLE_H
#include<memory>
#include "queue.h"


class ElementListaSimple{
public :
       TipoDato dato;
       std::shared_ptr<ElementListaSimple>  next = nullptr ;
   public :
       ElementListaSimple( const TipoDato& dato_) : dato{dato_} {};
};
bool insert(std::shared_ptr<ElementListaSimple>& front, const TipoDato& dato, int position) {
    std::shared_ptr<ElementListaSimple>& iterator = front;
    int pos{0};
    while(iterator != nullptr){
        if(pos == position){
            auto elem = std::make_shared<ElementListaSimple>(dato);
            elem->next = iterator->next;
            iterator->next = elem;
            return true;
        }
         pos++;
         iterator = iterator->next;
    }
    return false;
}
#endif // ELEMENTLISTASIMPLE_H
