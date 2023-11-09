#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <memory>
#include "tipos.h"

class fila
{
public:
    int size() const; //Devuelve el tamaño de la fila
    bool empty() const; //Devuelve true si la fila está vacía
    Persona getFront() const; //Getter de _front
    Persona getBack() const; //Devuelve referencia de la última persona de la fila
    void push(const Persona& dato); //Coloca persona en la fila
    //bool PersonPresent(const Persona& dato); //Busca una persona en la fila
    int PersonPresent(const Persona& dato); //Devuelve posición de la persona en la fila
    Persona& pop(void);  //Saca de la lista simplemente enlazada a la primera persona
    fila Split(const Persona &dato); //Divide la lista en 2

private:
    std::shared_ptr<Elemento> _ultimo=nullptr;
    friend std::ostream& operator<<(std::ostream& os, const fila& f){ //Este operador no cumple con (operador unario sin parámetros)
        //(operador binario con 1 parámetro + this)
        //Podemos encapsularlo dentro de la clase definíendolo como un método amigo
        //https://en.cppreference.com/w/cpp/language/friend
        std::shared_ptr<Elemento> aux=f._ultimo;
        if(aux!=nullptr)
        {
            os<<aux->dato.nombre<<"_";
            while(aux->next!=nullptr)
            {
                aux=aux->next; //avanzamos en la fila
                os<<aux->dato.nombre<<"_";
            }

        }
        return os;
    }

    std::shared_ptr<Elemento> getUltimo(void){return _ultimo;}
    void setUltimo(std::shared_ptr<Elemento> p){_ultimo=p;}
};


#endif // FILA_H
