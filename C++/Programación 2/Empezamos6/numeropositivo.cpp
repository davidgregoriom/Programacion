#include "numeropositivo.h"
#include <iostream>
#include <string>

using namespace std;

NumeroPositivo::NumeroPositivo(int a){
        numero = a;
    if(numero <= 0) throw string{"Hola buenos dias"};
    else cout <<  "Ya he salido";
}
