#include <iostream>
#include "binarytree.h"
#include "collections.h"
using namespace std;


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

