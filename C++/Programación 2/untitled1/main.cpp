#include <iostream>
#include <vector>
#include <functional>
#include "person.h"
#include "listin.h"

using namespace std;
void forEach (std::vector<person*> p, std::function<void(person*)> op) {
    for(auto elem:p){
            op(elem);
        }
}

person* find(std::vector<person*> p, std::function<bool(person*)> op){
    for(auto elem:p){
        if(op(elem)) return elem;
    }

    return nullptr;
}

std::vector<person*> filter(std::vector<person*> p, std::function<bool(person*)> op){
    std::vector<person*> result;
    for(auto elem:p){
        if(op(elem)) result.push_back(elem);
    }

    return result;
}




int main()
{
listin Listin;
    try{
            std::string option{"x"};
            while(option != "q"){
                std::cout << "Introduzca una opción: \n";
                std::cout << "a \tAñadir persona\n";
                std::cout << "l \tListar todas las personas\n";
                std::cout << "b \tBuscar una persona por nombre\n";
                std::cout << "le \tListar todas las personas de una determinda edad\n";
                std::cout << "q \tSalir\n";
                std::cin >> option;

                if(option == "a"){
                    std::cout << "Introduzca nombre, edad y telefono: ";
                    std::string nombre,telefono; int edad;
                    std::cin >> nombre >> edad >> telefono;
                    Listin.push_back(new person(nombre, edad, telefono));
                }else if(option == "l"){
                    forEach(listin, [](person* p)->void {
                        std::cout << *p;
                        std::cout << "----------\n";
                    });

                }else if(option == "b"){
                    std::cout << "Introduzca nombre de la pesona a buscar: ";
                    std::string nombre; std::cin >> nombre;
                    person* p = find(listin, [&](person * p)->bool{
                       return p->getName()==nombre;

                    });
                    if(p) std::cout << *p << "------------\n";

                }else if(option == "le"){
                    std::cout << "Introduzca la edad que desea buscar: ";
                    int edad; std::cin >> edad;
                    std::vector<person*> result = filter(listin, [&](person* p)->bool{
                        return p->getAge() == edad;
                    });

                    forEach(result, [](person* p)->void {
                        std::cout << *p;
                        std::cout << "----------\n";
                    });

                }
            }
        }catch(std::string e){
            std::cout << "ERROR: " << e << "\n";
        }

        // clear memory
        for(auto p:listin){
            delete p;
        }

        cout << "Adios, gracias!!" << endl;
        return 0;
}



























