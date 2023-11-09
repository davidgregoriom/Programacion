#include <iostream>
#include <memory>
using namespace std;



struct Complejo{
    float real, im;
};
template<typename T>
class Elem{
    public:
        Elem(T const & elem);
        T getData()const;
        void push_back(T const& e );
        shared_ptr<Elem <T>> getNext() const;
        shared_ptr<Elem <T>> getNext_prev() const;
    private:
        T elem;
        shared_ptr<Elem<T>>next;
        shared_ptr<Elem<T>>prev;
        shared_ptr<Elem<T>> setNext(shared_ptr<Elem<T>> n);
};

template<typename T>
Elem<T>::Elem(T const & elem): elem{elem}{
    next =nullptr;
}

template<typename T>
T Elem<T>::getData() const
{
    return elem;
}

template<typename T>
void Elem<T>::push_back(const T &e)
{
    if(next == nullptr){
      next=make_shared<Elem<T>>(e);
    }else next->push_back(e);
}

template<typename T>
shared_ptr<Elem<T> > Elem<T>::getNext() const
{
    return next;
}

template<typename T>
shared_ptr<Elem<T> > Elem::getNext_prev() const
{
    return prev;
}

template<typename T>
shared_ptr<Elem<T>> Elem<T>::setNext(shared_ptr<Elem<T> > n)
{
    next = n;
}
template<typename T>
void print(Elem<T> e){
    cout<< e.getData();

        if(e.getNext()) print<T>(*(e.getNext()));

}
template<typename T>
void print_reverse(Elem<T> e){
    cout<< e.getData();

        if(e.getNext_prev()) print<T>(*(e.getNext_prev()));

}
int main()
{
        Elem<int> lista =Elem<int>{1};
        lista.push_back(2);
        lista.push_back(3);
        print(lista);
        print_reverse(lista);
        return 0;
}
