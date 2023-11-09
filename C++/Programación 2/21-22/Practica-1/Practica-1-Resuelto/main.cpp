#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "persona.h"
#include <functional>
using namespace std;

shared_ptr<persona>find(vector<shared_ptr<persona>> const v, function< bool (shared_ptr<persona>)>f){
    for(auto p:v){
     if(f(p))return p;
    }
    return nullptr;//puntero nulo
}

bool some(vector<shared_ptr<persona>>v, function <bool(shared_ptr<persona>)> f){
        auto r=find(v,f);
        return (r!= nullptr);
    }

int main()
{
   vector<shared_ptr<persona>>censo;
   for(int i{0};i<5; i++){
       cout << "Introduce nombre :";
       string nombre; getline(cin, nombre);
       cout << "Introduce año de nacimiento:";
       int birthday; cin >>birthday;
       cout << "Introduce DNI :";
       string dni; getline(cin, dni);
       cout << "Introduce telefono :";
       string phone; getline(cin, phone);
       shared_ptr<persona>pPersona;
       pPersona = make_shared<persona>();
       pPersona -> setDni(dni);
       pPersona -> setPhone(phone);
       pPersona -> setName(nombre);
       pPersona -> setBirthday(birthday);

       censo.push_back(pPersona);
   }
   auto pepe = find (censo, [](shared_ptr<persona>p){
       return p -> getName() == "Pepe";
   });
   auto dni = find (censo, [](shared_ptr<persona>p){
       return p -> getDni() == "46464646C";
   });
   auto adult = find (censo, [](shared_ptr<persona>p){
       return p -> isAdult(2021);
   });
}
