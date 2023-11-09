#include <iostream>
#include <array>

using namespace std;

int main(){
    array<int,10> arr{2,3,4,5,4,3,4,8,7,9};
    array<int,10> contador{0,0,0,0,0,0,0,0,0,0};

    for(auto elem: arr){
        contador.at(elem-1)++;
    }
    int max{0};
    int elmaximo{0};
    int indice {0};
    for(auto elem: contador){
        if(elem > max){
            elmaximo= indice;
            max=elem;
        }
        indice++;
    }
    cout << "El numero que mas veces aparece es "<< elmaximo << " y aparece " << max << " veces\n";
}
