#include <iostream>
#include "tipodato.h"
#include "elementolistadoble.h"
#include <memory>
using namespace std;
void insertar_elemento(shared_ptr<elementolistadoble>e, const tipodato & dato){


    auto iterator=e;
    while (iterator != nullptr) {
        iterator = iterator->next;
    }
    shared_ptr<elementolistadoble>ultimo= iterator;



    ultimo->next = dato;
    dato->prev =ultimo;
}


int main()
{
    tipodato a1{"eda",8,false};
    tipodato a2{"programacion_2",8,true};

    auto e1=make_shared <elementolistadoble>(elementolistadoble{a1});
    auto e2=make_shared <elementolistadoble>(elementolistadoble{a2});

    e1->next =e2;
    e2->prev =e1;

    tipodato a3{"sistemas_digitales",8,false};
    auto e3=make_shared <elementolistadoble>(elementolistadoble{a3});
    e2->next =e3;
    e3->prev =e2;

    tipodato a4{"fisica",8,true};
    insertar_elemento(e1,a4);
}


