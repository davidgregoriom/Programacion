#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include "pesona.h"


template <class T>
class Lista
{
    template<class fT>friend std::ostream & operator <<(std::ostream & os, Lista<fT>const & l);
public:
    Lista();
    void insertar(std::shared_ptr<T> const &elem);
    T find(std::function<bool(T const &elem, unsigned long index)> f);
    Lista<T> filter(std::function<bool(T const &elem, unsigned long index)> f);
    void forEach(std::function<void(T const &elem, unsigned long index)> f);
    Lista<T> map(std::function<T(T const &elem, unsigned long index)> f);

private:
    std::vector<std::shared_ptr<T>> data;
};


template <class T>
Lista<T>::Lista()
{
}
template <class T>
void Lista<T>::insertar(const std::shared_ptr<T> &elem)
{
    data.push_back(elem);
}

template <class T>
T Lista<T>::find(std::function<bool(T const &, unsigned long)> f)
{
    for (unsigned long i; i < data.size(); i++)
    {
        if (f(data.at(i), i))
            return data.at(i);
    }
    throw std::string{"Element not found"};
}

template <class T>
Lista<T> Lista<T>::filter(std::function<bool(T const &, unsigned long)> f)
{
    Lista<T> result;
    for (unsigned long i; i < data.size(); i++)
    {
        if (f(data.at(i), i))
            result.push_back(data.at(i));
    }
    return result;
}

template <class T>
void Lista<T>::forEach(std::function<void(T const &, unsigned long)> f)
{
    for (unsigned long i; i < data.size(); i++)
    {
        f(data.at(i), i);
    }
}

template <class T>
Lista<T> Lista<T>::map(std::function<T(T const &, unsigned long)> f)
{
    Lista<T> result;
    for (unsigned long i; i < data.size(); i++)
    {
        result.push_back(f(data.at(i), i));
    }
    return result;
}


#endif // LISTA_H
