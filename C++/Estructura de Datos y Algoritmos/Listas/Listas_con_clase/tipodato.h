#ifndef TIPODATO_H
#define TIPODATO_H
#include <string>
#include <iostream>
#include <memory>

using namespace  std;

class TipoDato
{
public:
    TipoDato();
    shared_ptr<TipoDato> next =nullptr;

};

#endif // TIPODATO_H
