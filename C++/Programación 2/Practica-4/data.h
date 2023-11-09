#ifndef DATA_H
#define DATA_H
#include "pair.h"
#include <vector>
#include <iostream>
using namespace std;

template<typename K,typename V>
class Data
{
public:
    friend std::ostream & operator<<(std::ostream & os, Data<K,V>const & v);
    Data();
    Pair<K,V> at
    void push(Pair<K,V> const & p );
    vector<pair<K, V> > getDatos() const;
    void setDatos(const vector<pair<K, V> > &value);

private:
    vector<pair<K,V>> datos;
};
template<typename K,typename V>
Data<K,V>::Data()
{

}
template<typename K,typename V>
vector<pair<K, V> > Data<K,V>::getDatos() const
{
    return datos;
}
template<typename K,typename V>
void Data<K,V>::setDatos(const vector<pair<K, V> > &value)
{
    datos = value;
}


template<typename K,typename V>
std::ostream & operator<<(std::ostream & os,Data<K,V> const & v){
    std::cout<< v.Data;
    return os;
}
#endif // DATA_H
