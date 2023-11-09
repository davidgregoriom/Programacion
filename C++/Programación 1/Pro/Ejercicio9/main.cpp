#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 7> notas ={1,2,34,5,6,7,7};
    int posicion= -1;
    int contador=0;

    for(auto num : notas){
        posicion=posicion+1;

        if (num==7) {
           contador=contador+1;
        }
    }
    cout<< "El numero 7 ha salido " << contador << " veces";


}
