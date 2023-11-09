#ifndef DB_H
#define DB_H
#include "data.h"
#include <memory>
#include <functional>
#include <iostream>

using namespace std;

template<typename K,typename V>
class DB
{
    friend std::ostream & operator<<(std::ostream & os,DB const & v);

public:
    DB();
    void forEach(K const & v, std::function<void(V)> const & op);
    K filter(K const & v, std::function<bool(V)> const & f);
    V find(K const & v, std::function<bool(V)> const & f);

private:
    vector<shared_ptr<Data<K,V>>> db;
};


template <typename T, typename Y>
void forEach(T const & v, std::function<void(Y)> const & op){
  for(auto elem: v){
    op(elem);
  }
}
template <typename T, typename Y>
T filter(T const & v, std::function<bool(Y)> const & f){
  T result;
  for(auto elem: v){
    if(f(elem)) result.push_back(elem);
  }

  return result;
}
template <typename T, typename Y>
Y find(T const & v, std::function<bool(Y)> const & f){

  for(auto elem: v){
    if(f(elem)) return elem;
  }

  return Y{};
}
template<typename K,typename V>
std::ostream & operator<<(std::ostream & os,DB<K,V> const & v){
    std::cout<< v.DB;
    return os;
}
#endif // DB_H
