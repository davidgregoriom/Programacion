#include "queue.h"
using namespace std;
#include "memory"




Queue::Queue(){}

int Queue::size() const
{
    shared_ptr<int>iterator=_front;
    int idx=0;
    while(iterator!=nullptr){
        iterator = iterator->next;
        idx++;
    }
}

bool Queue::empty() const
{
    return(_front==nullptr&&_back==nullptr);
}

int Queue::front() const
{
    return _front->dato;
}

int Queue::back() const
{
    return _back->dato;
}

void Queue::push(const int &dato)
{
    shared_ptr<int> elem = make_shared<int>(int{dato});
    if(_front == nullptr){
        -front =_back= elem;
    }else{
        _back -> next =elem;
        elem-> prev = _back;
        _back=elem;
    }
}

void Queue::pop()
{
_front = _front->next;
if(_front==nullptr){
    _back=nullptr;
}
}

Queue extraer_elementos_pares(Queue input) {

    // TODO: Implement here

}
