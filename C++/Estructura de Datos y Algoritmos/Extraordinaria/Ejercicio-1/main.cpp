#include <memory>
#include <stdlib.h>
#include <iostream>
#include <memory>

using namespace std;

struct ElementoArbolBinario {
   int dato;

   std::shared_ptr<ElementoArbolBinario> left = nullptr;
   std::shared_ptr<ElementoArbolBinario> right = nullptr;
    ElementoArbolBinario(int d) : dato{d} {}
};


class ArbolBinario {
   public:
       ArbolBinario() {}
        ArbolBinario(int  dato) {
            _root= std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
        }

       void addElement(int dato) {
           // Esta función inserta nodos aleatoriamente en el árbol
           auto elem = std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
           std::shared_ptr<ElementoArbolBinario>* next = &_root;
           while (*next != nullptr) {
               next = (rand() % 2) ? &((*next)->left) : &((*next)->right);
           }
           *next = elem;
       }
       int _size (shared_ptr<ElementoArbolBinario>elemento)const {
          int tamanoderecha=_size(elemento->left);
          int tamanoizquierda=_size(elemento->right);
          return 1+ tamanoderecha+tamanoizquierda;

       }
       int size()const  {

           // TODO: Tú código empieza aquí
           if(_root == nullptr){

           return -1;  // La función debe devolver el número de nodos del árbol
           }
               _size(_root);


       }









protected:
       std::shared_ptr<ElementoArbolBinario> _root = nullptr;
};


int main() {
    ArbolBinario tree;
    tree.addElement(1);
   tree.addElement(2);
   tree.addElement(3);
   tree.addElement(5);
   tree.addElement(8);
   tree.addElement(11);

   std::cout << "Number of nodes: " << tree.size() << std::endl;
}

