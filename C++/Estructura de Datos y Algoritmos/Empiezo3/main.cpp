#include <memory>
#include <functional>
#include <iostream>

using namespace std;

/*
using TipoDato = std::string;

struct ElementoArbol {
    TipoDato dato;
    std::shared_ptr<ElementoArbol> left = nullptr;
    std::shared_ptr<ElementoArbol> right = nullptr;
};

struct ElementoQueue {
    ElementoArbol dato;
    std::shared_ptr<ElementoQueue> next = nullptr;
};

class Queue {
    public:
        Queue() {}
        bool empty() const { return _front == nullptr;}
        ElementoArbol& front() const { return _front->dato; }
        void push(const ElementoArbol& dato) {
            auto elem = std::make_shared<ElementoQueue>(ElementoQueue{dato});
            if (empty()) {
                _front = _back = elem;
            }
            else {
                _back->next = elem;
                _back = _back->next;
            }
        }
        void pop() {
            _front = _front->next;
        }

    protected:
        std::shared_ptr<ElementoQueue> _front = nullptr;
        std::shared_ptr<ElementoQueue> _back = nullptr;
};

class BinaryTree {
    protected:
        std::shared_ptr<ElementoArbol> root = nullptr;

    public:
        BinaryTree(const TipoDato& dato) {
            root = std::make_shared<ElementoArbol>(ElementoArbol{dato});
        }

        void add_left(BinaryTree& tree) { root->left = tree.root; }
        void add_right(BinaryTree& tree) { root->right = tree.root; }

        // Breadth first search (recorrido en anchura)
        void bfs(std::function<void (const TipoDato&)> action) const {
            Queue queue;
            queue.push(*root);
            while (!queue.empty()) {
                ElementoArbol elem = queue.front();
                queue.pop();
                action(elem.dato);
                if (elem.left) { queue.push(*elem.left);}
                if (elem.right) { queue.push(*elem.right);}
            }
        }
};

struct ElementoLista {
    TipoDato dato;
    std::shared_ptr<ElementoLista> next = nullptr;
};

class LinkedList {
    public:
        LinkedList() {}
        void push_back(const TipoDato& dato) {
            auto elem = std::make_shared<ElementoLista>(ElementoLista{dato});
            if (_front == nullptr) {
                _front = elem;
            }
            else {
                auto iterator = _front;
                while (iterator->next != nullptr) {
                    iterator = iterator->next;
                }
                iterator->next = elem;
            }
        }

        void for_each(std::function<void (const TipoDato&)> action) {
            auto iterator = _front;
            while (iterator != nullptr) {
                action(iterator->dato);
                iterator = iterator->next;
            }
        }

    protected:
        std::shared_ptr<ElementoLista> _front = nullptr;
};

int main() {
    BinaryTree tree{"root"};

    BinaryTree t11{"11"};
    BinaryTree t12{"12"};
    tree.add_left(t11);
    tree.add_right(t12);

    BinaryTree t22{"22"};
    BinaryTree t23{"23"};
    BinaryTree t24{"24"};
    t11.add_right(t22);
    t12.add_left(t23);
    t12.add_right(t24);

    LinkedList lista;
    tree.bfs([&lista](const TipoDato& dato){
        lista.push_back(dato);
    });

    lista.for_each([](const TipoDato& dato){
        std::cout << dato << std::endl;
    });
}
*/
/*
void _dfs_postorder(std::shared_ptr<ElementoArbol> root,
                    std::function<void (TipoDato&)> action) {
    for (auto child: root->children) {
        _dfs_postorder(child, action);
    }
    action(root->dato);
}

void Tree::dfs_postorder(std::function<void (TipoDato&)> action) const {
    _dfs_postorder(root, action);
}
*/

struct TipoDato { std::string name; };

class Element {
    public:
        // Members
        TipoDato dato;
        std::shared_ptr<Element> next = nullptr;
    public:

        // Constructor
        Element(const TipoDato& dato_) : dato{dato_} {};
        int size(std::shared_ptr<Element> lista) {
            if (lista == nullptr) {
                return 0;
            }
            return 1 + size(lista->next);
        }

        bool empty(std::shared_ptr<Element> lista) {
            return size(lista) == 0;

        }
};



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


    // Los podemos imprimir, del primero al último:
    std::shared_ptr<Element> iterator = lista;  // primer elemento
    while (iterator != nullptr) {
        std::cout << iterator->dato.name << std::endl;
        iterator = iterator->next;  // el iterador apunta al siguiente elemento
    }
     cout << empty;
}
