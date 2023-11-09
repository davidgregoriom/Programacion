
#include <memory>

#include <iostream>



void print_list(std::shared_ptr<Element> lista) {

    std::shared_ptr<Element> iterator = lista;

    while (iterator != nullptr) {

        std::cout << iterator->dato.name << std::endl;

        iterator = iterator->next;

    }

}



int main() {

    // Tenemos algunos datos

    TipoDato t1{"nicolás"};

    TipoDato t2{"marina"};

    TipoDato t3{"humberto"};



    // Tenemos elementos que almacenan los datos

    std::shared_ptr<Element> e1 = std::make_shared<Element>(Element{t1});

    std::shared_ptr<Element> e2 = std::make_shared<Element>(Element{t2});

    std::shared_ptr<Element> e3 = std::make_shared<Element>(Element{t3});



    // Los podemos poner en "orden" (uno detrás de otro)

    e1->next = e2;

    e2->next = e3;



    // La lista la representamos por el primer elemento

    std::shared_ptr<Element> lista = e1;

    print_list(lista);

}
