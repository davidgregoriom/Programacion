#include "tipodato.h"
#include <iostream>
using namespace std;



TipoDato::TipoDato(   int cliente_id): cliente_id{cliente_id}
{

}

int TipoDato::getTipoDato()
{
    return cliente_id;
}
