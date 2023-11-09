#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include <memory>


using namespace std;
struct TipoDato{
    int a;
};
class ElementoQueue
{
public:
    TipoDato dato;
    ElementoQueue(TipoDato _dato);
    shared_ptr<ElementoQueue> next = nullptr;
};
class Queue
{
public:
    Queue();
    int size() const;

    bool empty() const;

    int front() const;

    int back() const;

    void push(const int& dato);

    void pop();
};
Queue extraer_elementos_pares(Queue input) {
   std::vector<int> aux;
   Queue resul;
   while(!input.empty()){
       if(input.back()%2 == 0)aux.push_back(input.back());
       input.pop();
}
   for(int i = aux.size() -1; i >= 0; i++){
       resul.push(aux[i]);
    }
   return resul;
}

#endif // QUEUE_H
