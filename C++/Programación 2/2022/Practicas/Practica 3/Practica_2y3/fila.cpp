#include "fila.h"

int fila::size() const{
    int cont=0;
    std::shared_ptr<Elemento> aux=_ultimo;

    if(aux!=nullptr)
    {//Ojo con indireccionar el nullptr... segmentation fault...
        cont++; //Contamos el primer elemento de la lista simplemente enlazada

        while(aux->next!=nullptr)
        {
            cont++; //Contamos uno
            aux=aux->next; //avanzamos en la fila
        }

    }

    return cont;
}

bool fila::empty() const{
    if (this->size()==0)
    {//Dede un método podemos usar otros métodos
        return true;
    }

    //Otra manera menos costosa computacionalmente
    /*if(_ultimo==nullptr)
    {
        return true;
    }*/

    return false;
}

Persona fila::getBack()const{ //Devolvemos la última persona de la fila
    return _ultimo->dato;
}

Persona fila::getFront() const{ //Recorremos la fila buscando el primero
    std::shared_ptr<Elemento> aux=_ultimo;
    if(_ultimo!=nullptr)
    {
        while(aux->next!=nullptr)
        {
            aux=aux->next; //avanzamos en la fila
        }

        return aux->dato;
    }
    else
    {
        throw std::string{"Fila vacia"};
    }
}

void fila::push(const Persona& dato){ //Llega la persona dato a la fila
    if(_ultimo==nullptr)
    {//No hay nadie en la fila, dato es la primera persona en llegar
        _ultimo=std::make_shared<Elemento>(dato);
    }
    else
    {//Hay mas gente en la fila=> Ponemos dato en último lugar
        std::shared_ptr<Elemento> aux=std::make_shared<Elemento>(dato);
        //"Pedimos vez"
        aux->next=_ultimo; //El que esté delante de la nueva persona será el último de la fila
        //Actualizamos nuestro TAD
        _ultimo=aux; //Actualizamos el puntero a último. Ahora la persona agregada a la lista será la última
    }
}
/*
bool Fila::PersonPresent(const Persona &dato){ //Buscamos a la persona dato en la fila
    std::shared_ptr<Elemento> aux=_ultimo;

    if(_ultimo!=nullptr)
    {
        while(aux->next!=nullptr)
        {
            if(aux->dato==dato) //Atención para poder comparar personas con operador igualdad == debemos indicar como operar mediante sobercarga
            {//Si encontramos a la persona que buscamos devolvemos un true
                return true;
            }
            aux=aux->next; //avanzamos en la fila
        }

        return false; //No hemos encontrado la persona que buscamos
    }
    else
    {
        throw std::string{"Fila vacia"};
    }
}*/
int fila::PersonPresent(const Persona &dato){ //Buscamos a la persona dato en la fila y devolvemos su posición
    std::shared_ptr<Elemento> aux=_ultimo;
    int posicion{0};

    if(_ultimo!=nullptr)
    {
        while(aux->next!=nullptr)
        {
            if(aux->dato==dato) //Atención para poder comparar personas con operador igualdad == debemos indicar como operar mediante sobercarga
            {//Si encontramos a la persona que buscamos devolvemos un true
                return posicion;
            }
            aux=aux->next; //avanzamos en la fila
            posicion++;
        }

        if(aux->dato==dato)
        {
            return posicion;
        }

        throw std::string{"No esta la persona que buscas"}; //No hemos encontrado la persona que buscamos
    }
    else
    {
        throw std::string{"Fila vacia"}; //En la fila no había nadie
    }
}

Persona& fila::pop(void)
{//Quitamos el primero de la fila
    std::shared_ptr<Elemento> aux=_ultimo;
    std::shared_ptr<Elemento> anteriorAaux=nullptr;

    if(_ultimo!=nullptr)
    {//Hay gente
        while(aux->next!=nullptr)
        {//Recorremos hasta el primer elemento de la lista
            anteriorAaux=aux; //Nos quedamos con el anterior
            aux=aux->next; //avanzamos en la fila
        }
    }
    else
    {//No hay nadie
        throw std::string{"Fila vacia"};
    }

    if(anteriorAaux==nullptr)
    {//estaríamos en el caso de una única persona en la fila
        aux=_ultimo;
        _ultimo=nullptr; //Como ya "ha hecho su compra" se marcha, y la fila queda vacía
    }
    else
    {//Resto de casos
        anteriorAaux->next=nullptr; //Hacemos al segundo primero
    }

    return aux->dato;
}

fila::Split(const Persona &dato)
{
    std::shared_ptr<Elemento> aux=_ultimo;
    std::shared_ptr<Elemento> anteriorAaux=nullptr;

    fila otraFila;
    int posicion{0};

    try{
        posicion=PersonPresent(dato);
    }
    catch(const std::string &s)
    {
        throw std::string{"No estaba la persona indicada..."};
    }

    int tam=size();

    for(int i{0};i<(tam-posicion-1);i++)
    {
        otraFila.push(this->pop()); //Añadimos en la nueva fila la persona que eliminamos de la fila
    }
    //Hasta aquí tendríamos en la fila encapsulada desde el _ultimo hasta la persona dato incluida
    //Y en otraFila desde la persona dato (no incluida) hasta el primero

    //Pero.... el enunciado pide:
    // Dicho método devolverá la lista desde la persona dato hasta el final y modificará la lista encapsulada

    //Para poder cumplir con el enunciado debemos reasignar las listas (
    //Para ello en la parte privada de la clase podemos agregar el getter y setter del puntero _ultimo
    //Importante que sea en la parte privada!!!
    //Si lo hicieramos en la parte publica "cualquiera" podría modificar nuestra lista simplemente enlazada
    auto p=_ultimo; //Puntero auxiliar para _ultimo

    //Cambiamos los últimos de las 2 listas
    _ultimo=otraFila.getUltimo();
    otraFila.setUltimo(p);

    return otraFila; //Devolvemos la mitad de la fila inicial que pide el enunciado

}
