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


//Apartado_4:
vector<shared_ptr<int>> filter (array<shared_ptr<int>,10>const & v,function<bool(int)>g){
        vector<shared_ptr<int>> result;
        for(auto pelem: v){
            if(g(*pelem))result.push_back(make_shared<int>(*pelem));
        }
        return result;
}

int main(){
    //Apartado_1:
    array<shared_ptr<int>,10>arr1;
    //Apartado_2:
    for(int i{0};i<arr1.size();i++){
        cout << "Introduzca el " << i + 1 << "º valor \n ";
        int valor;
         cin >> valor;
        shared_ptr<int> paux = make_shared<int>(valor);
          arr1.at(i) = paux ;
    }
    //Apartado_3:
    ///for(int i{0};i<arr1.size();i++){
       /// cout << "El " << i+1 << " valor del array es: " << *arr1.at(i) << "\n";
       ///puede ser valido pero es más fácil:
      for(auto pelem:arr1){
        cout << *pelem << "\n";
      }
    //Apartado_4:
    auto espar =[](int a){
        return a%2 ==0;
    };
    auto v1 = filter(arr1,espar);
    //Apartado_5:
    for(auto pelem:v1){
        cout<<*pelem<< "\n";
    }
    return 0;
}
