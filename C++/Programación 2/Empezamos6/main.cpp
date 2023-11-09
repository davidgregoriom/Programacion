#include <iostream>
#include "numeropositivo.h"
using namespace std;

int main()
{
    try{
        NumeroPositivo a{5};
        }catch(string e){
            cout << "Ha habido una excepcion" <<"\n" <<e ;
        }
    }
