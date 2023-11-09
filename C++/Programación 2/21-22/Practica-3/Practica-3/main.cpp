#include <iostream>
#include "tiempo.h"

using namespace std;

int main()
{
    cout << "Introduce 2 tiempos\n" << endl;


    Tiempo a;
    Tiempo b;
    try{
    cout << "Tiempo 1:";
    cin >> a;
    }catch(string msg){
        cout << msg << endl;
    }try{
    cout << "Tiempo 2:";
    cin >> b;
    }catch(string msg){
        cout << msg << endl;
    }
    cout << "Suma:"<< a+b <<endl;
    cout << "Resta:"<< a-b <<endl;
    cout << "Comparación:\n";
    if(a==b){
        cout << "Son iguales los tiempos"<< endl;
    }else{
        cout << "No son iguales los tiempos"<< endl;
    }

}
