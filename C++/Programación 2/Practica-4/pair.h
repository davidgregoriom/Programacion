#ifndef PAIR_H
#define PAIR_H
#include <iostream>

using namespace std;
template<typename K,typename V>
class Pair
{
public:
    friend std::ostream & operator<<(std::ostream & os, Pair<K,V>const & v);


    Pair(K v1,V v2);
    K clave() const;
    void setClave(const K &clave);

    V valor() const;
    void setValor(const V &valor);

private:
    K _clave;
    V _valor;
};
template<typename K,typename V>
Pair<K,V>::Pair(K v1,V v2)
{
    _clave=v1;
    _valor=v2;
}
template<typename K,typename V>
K Pair<K,V>::clave() const
{
    return _clave;
}
template<typename K,typename V>
void Pair<K,V>::setClave(const K &clave)
{
    _clave = clave;
}
template<typename K,typename V>
V Pair<K,V>::valor() const
{
    return _valor;
}
template<typename K,typename V>
void Pair<K,V>::setValor(const V &valor)
{
    _valor = valor;
}

template<typename K,typename V>
std::ostream & operator<<(std::ostream & os,Pair<K,V> const & v){
    std::cout<< v.Pair;
    return os;
}
#endif // PAIR_H
