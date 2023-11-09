#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
    /*
    Pedido a{2, "limon"};
    Pedido b{5, "limon"};
    Pedido c{2, "manzana"};
    Pedido d{3, "pera"};

    shared_ptr<ElementoLista> e1 = make_shared<ElementoLista>(ElementoLista{a});
    shared_ptr<ElementoLista> e2 = make_shared<ElementoLista>(ElementoLista{b});
    shared_ptr<ElementoLista> e3 = make_shared<ElementoLista>(ElementoLista{c});
    shared_ptr<ElementoLista> e4 = make_shared<ElementoLista>(ElementoLista{d});

    e1->next=e2;
    e2->next=e3;
    e3->next=e4;

    shared_ptr<ElementoLista>lista = e1;


    */
        ElementoLista a{{3, "manzana"}};
        ElementoLista b{{2, "pera"}, make_shared<ElementoLista>(a)};
        ElementoLista c{{2, "manzana"}, make_shared<ElementoLista>(b)};


        Lista l;
        l.setInicio(c);


        Lista other;
        other = l.unificar();

        other.print();
}
