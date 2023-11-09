#include <memory>
#include <iostream>

struct TipoDato { std::string name; };

class Element {
    public:
        // Members
        TipoDato dato;
        std::shared_ptr<Element> next = nullptr;
    public:
        // Constructor
        Element(const TipoDato& dato_) : dato{dato_} {};
};
void print_list(std::shared_ptr<Element> lista) {
    std::shared_ptr<Element> iterator = lista;
    while (iterator != nullptr) {
        std::cout << iterator->dato.name << std::endl;
        iterator = iterator->next;
    }
}
void for_each(std::shared_ptr<Element> lista,std::function<void (TipoDato&)> action) {
    // Iterate the list as usual
    std::shared_ptr<Element> iterator = lista;
    while (iterator != nullptr) {
        action(iterator->dato); // Call the action
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
