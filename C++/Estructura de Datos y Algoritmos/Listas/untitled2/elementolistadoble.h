#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include <memory>
#include <tipodato.h>
using namespace std;

class elementolistadoble
{
public:
    elementolistadoble(const tipodato & dato);

    tipodato dato;
    shared_ptr<elementolistadoble> next= nullptr;
    shared_ptr<elementolistadoble> prev= nullptr;

};

#endif // ELEMENTOLISTADOBLE_H
