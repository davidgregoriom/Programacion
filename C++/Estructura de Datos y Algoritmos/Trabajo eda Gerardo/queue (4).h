#ifndef QUEUE_H
#define QUEUE_H
#include "tipodato.h"
#include "elementolistadoble.h"
#include <memory>
using namespace std;


class queue
{
 //friend   ostream & operator<< (ostream & os, queue const & c);

public:
    queue();
    int size() const;
    bool empty() const;

    TipoDato&  front() const;
    TipoDato& back() const;


    void push(const TipoDato& dato);
    void pop();


private:
    std::shared_ptr<ElementoListaDoble> _front = nullptr;
    std::shared_ptr<ElementoListaDoble> _back = nullptr;
};
//ostream & operator<< (ostream & os, queue const & c);

#endif // QUEUE_H
