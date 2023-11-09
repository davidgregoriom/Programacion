#include "lista.h"
#include <vector>

std::shared_ptr<ElementoLista> Lista::getInicio() const
{
    return inicio;
}

void Lista::push(const Pedido & p)
{
    std::shared_ptr<ElementoLista> elem = std::make_shared<ElementoLista>(ElementoLista{p});
    if(inicio == nullptr){
        inicio = elem;
    }else{
        elem->setNext(inicio);
        inicio = elem;
    }
}

void Lista::setInicio(const ElementoLista &value)
{
    std::shared_ptr<ElementoLista> elem = std::make_shared<ElementoLista>(value);
    inicio = elem;
}

int existing_fruit(std::shared_ptr<ElementoLista> const &fruit, std::vector<Pedido> const &v)
{
    int pos{0};
    for(auto elem:v){
        if(elem.fruta == fruit->getPedido().fruta)return pos;
        pos++;
    }
    return -1;
}
/*
Pedido &Lista::front(std::shared_ptr<ElementoLista> lista)
{
    return lista->pedido;
}
*/
/*void Lista::push_front(std::shared_ptr<ElementoLista> &lista)
{
    std::shared_ptr<ElementoLista>elem =std::make_shared<ElementoLista>(ElementoLista{pedido});
    if(empty(lista)){
        lista=elem;
    }else{
        elem->next = lista;
        lista = elem;
    }
}
*/

Lista Lista::unificar(void) const{
    Lista resul;
    std::vector<Pedido> vec;
    std::shared_ptr<ElementoLista> iter = inicio;
    while(iter != nullptr){
        if(existing_fruit(iter, vec) == -1)vec.push_back(iter->getPedido());
        else vec[existing_fruit(iter, vec)].cantidad += iter->getPedido().cantidad;
        iter = iter->next;
    }
    for(auto elem: vec){
        resul.push(elem);
    }
    return resul;
}
/*
bool Lista::empty(std::shared_ptr<ElementoLista> lista)
{
    return (lista== nullptr);
}
*/
void Lista::print() const
{
    std::shared_ptr<ElementoLista> iter = inicio;
    while(iter != nullptr){
        std::cout << iter->pedido.fruta << ',' << iter->pedido.cantidad << '\n';
        iter = iter->next;
    }
}

std::shared_ptr<ElementoLista> ElementoLista::getNext() const
{
    return next;
}

Pedido ElementoLista::getPedido() const
{
    return pedido;
}

void ElementoLista::setNext(const std::shared_ptr<ElementoLista> &value)
{
    next = value;
}
