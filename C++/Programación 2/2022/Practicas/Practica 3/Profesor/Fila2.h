#ifndef FILA2_H
#define FILA2_H

#include "tipos.h"

class Fila2{ //lista doblemente enlazada
private:
    std::shared_ptr<Elemento2> _ultimo=nullptr;
    std::shared_ptr<Elemento2> _primero=nullptr;
public:
    Persona pop()
    {//Elimina el primer elemento de la lista
        auto aux=_primero;

        if(_primero!=nullptr)
        {

            _primero=_primero->prev; //Reasignamos el primer elemento de la lista al segundo (el que va detrás del primero)
            aux->prev=nullptr;
            _primero->next=nullptr; //El anterior segundo será el primer elemento (el que apunta a nullptr)

            return aux->dato;
        }
        else
        {
            throw std::string{"No hay nadie..."};
        }

    }

    void push(const Persona &p)
    {//Añadimos persona a la lista doblemente enlazada por el final
        auto pun=std::make_shared<Elemento2>(p); //creamos puntero a elemento2

        if(_ultimo==nullptr and _primero==nullptr)
        {//No hay nadie => ultimo y primero serán el nuevo elemento
            _ultimo=pun;
            _primero=pun;
        }
        else
        {//Hay gente
            _ultimo->prev=pun; //El que antes era ultimo (su prev apuntaba a nullptr) ahora es penultimo
            pun->next=_ultimo; //El nuevo elemento se coloca "detrás" del _ultimo

            _ultimo=pun; //Actualizamos _ultimo de la lista
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Fila2& f){
        std::shared_ptr<Elemento2> aux=f._ultimo;
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
};

#endif // FILA2_H
