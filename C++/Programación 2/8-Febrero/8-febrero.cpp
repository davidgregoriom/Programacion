#include <array>
#include <iostream>
#include <functional>
#include <memory>
#include <vector>
using namespace std;

//Realizar un programa que haga lo siguiente:

    //Crear un array arr1 de 10 elementos de punteros a números enteros
    //Pedir al usuario que introduzca el valor de los 10 números.
    //Mostrar los números por pantalla.
    //A través de una función filter (programación funcional) generar un vector vec de punteros con los números pares.
    //Mostrar por pantalla los números pares.



auto filter =  [](vector<shared_ptr<int>>const & v,function<bool(int)>g){
        vector<shared_ptr<int>> result;
        for(auto elem: v){
            if(g(*elem))result.push_back(elem);
        }
        return result;
    };

int main(){
    array<shared_ptr<int>,10>arr1;
    vector<shared_ptr<int>>v;
    for(int i{0};i<arr1.size();i++){
        cout << "Introduzca el " << i + 1 << "º valor \n ";
        shared_ptr<int> a = make_shared<int>();
          cin >> *a;
          arr1.at(i) =a ;
    }
    for(int i{0};i<arr1.size();i++){
        cout << "El " << i+1 << " valor del array es: " << *arr1.at(i) << "\n";

    }
    auto pares =[] (int a) {return (a%2== 0);};
    auto v1 = filter(v,pares);

    return 0;
}
