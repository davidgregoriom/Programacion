#include "tipodato.h"
#include <iostream>
using namespace std;



TipoDato::TipoDato(   string XD): XD{XD}
{

}

string TipoDato::getTipoDato()
{
    return XD;
}
