#include "queue.h"
#include "tipodato.h"
#include "elementolistadoble.h"

queue::queue()
{
    _front = nullptr;
    _back = nullptr;
}
int queue::size() const
{
    shared_ptr<ElementoListaDoble> iterator = _front;
    int idx=0;
    while(iterator != nullptr){
        idx++;
        iterator = iterator->prev;
    }
    return idx;
}

TipoDato & queue::front() const
{

          return _front->dato;
}

void queue::push(TipoDato const & dato){
    shared_ptr<ElementoListaDoble> elem = make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
if(_front == nullptr){
    _back = elem;
    _front = elem;

}
else{
    _back->prev = elem;
    _back = elem;
}
}
void queue::pop()
{
if(size() == 0){
    cout << "No puedes sacar ya que no hay";
}
else if(size() == 1){
    _front = nullptr;
    _back = nullptr;
}
else{
    _front = _front->prev;
    _front->next = nullptr;
}

}
//ostream & operator<< (ostream & os, queue const & c){
  //os << c.size() << endl;
  //return os;
//}



