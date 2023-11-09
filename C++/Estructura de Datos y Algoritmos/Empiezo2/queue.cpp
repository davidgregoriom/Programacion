#include "queue.h"
#include <memory>
using namespace std;
#include <iostream>

Queue::Queue()
{

}

int Queue::size() const
{
    shared_ptr<ElementListaDoble> iterator = _front;
     int idx = 0;
     while (iterator != nullptr) {
         iterator = iterator->next;
         idx++;
     }
     return idx;
}

bool Queue::empty() const
{
     if(size() ==0)return true;
     else return false;
}

Persona &Queue::front() const
{
    return _front -> dato;
}

Persona &Queue::back() const
{
    return _back -> dato;
}

void Queue::push(const Persona &dato)
{
     shared_ptr<ElementListaDoble> elem = make_shared<ElementListaDoble>(ElementListaDoble{dato});
     if (_front == nullptr) {
         _front = elem;
         _back = elem;
     }
     else {
         _front->prev = elem;
         elem->next = _front;
         _front = elem;
     }
}

void Queue::pop()
{
    _back = _back ->prev;
    _back->next = nullptr;
    if(_back == nullptr){
        _front = nullptr;
    }
}

void Queue::sneak_in(const Persona &contact, Queue &friends)
{
    std::shared_ptr<ElementListaDoble> iterator = _front;
    while(iterator != nullptr){
        if(iterator->dato == contact){
            (friends._back)-> next = iterator->next;
            (iterator->next)->prev = friends._back;
            iterator->next = friends._front;
            (friends._front)->prev = iterator;
        }
        iterator = iterator->next;
    }
    //if(iterator->next == nullptr) std::cout << "No hay ";

}

