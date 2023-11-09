#include <iostream>
#include "numero_complejo.h"

using namespace std;

template<typename T>



T suma(T  const & a ,T  const & b){
    return a + b;
}

void print(int a){
    cout<< "soy el numero " << a << "\n";
}

void print(string const & a){
    cout << "soy el string " << a<< "\n";
}

int main()
{
    cout<< suma <float>(3.2,3.2);
    print(1);
    print("hola");

   Numero_Complejo uno{1,2};
   Numero_Complejo dos{2,3};

   auto lasuma = suma<Numero_Complejo>(uno,dos);
    return 0;
}
