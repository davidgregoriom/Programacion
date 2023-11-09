#ifndef TIPOS_H
#define TIPOS_H

#include <string>
#include <memory>
#include <iostream>

struct Persona{
    std::string nombre;
    int edad{0};

     bool operator ==(const Persona &op2) const{
             if(op2.nombre==this->nombre and op2.edad==this->edad)
             {
                 return true;
             }
             return false;
     }

     friend std::ostream& operator<<(std::ostream &os, const Persona &p)
     {
         os<<p.nombre<<"_"<<p.edad<<std::endl;
         return os;
     }

};



struct Elemento{ //Nodo lista simplemente enlazada
    Elemento(const Persona &p){dato=p;}
    Persona dato;
    std::shared_ptr<Elemento> next{nullptr};
};

struct Elemento2{ //Nodo lista doblemente enlazada
    Elemento2(const Persona &p) {dato=p;};
    Persona dato;
    std::shared_ptr<Elemento2> next{nullptr};
    std::shared_ptr<Elemento2> prev{nullptr};
};

#endif // TIPOS_H
