#ifndef BINARYTREE_H
#define BINARYTREE_H
#pragma once

#include "collections.h"
#include <memory>
#include <functional>

using TipoDato = std::string;



class ElementoArbolBinario {
    public:
        // Members
        TipoDato dato;
        std::shared_ptr<ElementoArbolBinario> left = nullptr;
        std::shared_ptr<ElementoArbolBinario> right = nullptr;
    public:
        // Constructor
        ElementoArbolBinario(const TipoDato& dato_) : dato{dato_} {}
};
struct ElementoQueue {
   ElementoArbolBinario dato;
   std::shared_ptr<ElementoQueue> next = nullptr;
};

// Una cola
class Queue {
    public:
        Queue();

        bool empty() const{ return _front== nullptr;}
        void push(const ElementoArbolBinario& dato){
            auto elem = std::make_shared<ElementoQueue>(ElementoQueue{dato});
            if (empty()) {
                _front = _back = elem;
            }
            else {
                _back->next = elem;
                _back = _back->next;
            }

        }

        void pop(){
            _front = _front->next;
        }

    protected:
        std::shared_ptr<ElementoQueue> _front = nullptr;
        std::shared_ptr<ElementoQueue> _back = nullptr;
};

class BinaryTree {
    protected:
        std::shared_ptr<ElementoArbolBinario> root = nullptr;

    public:
        BinaryTree(const TipoDato& dato){
        root = std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
            // Creates a tree with a value
}
        void add_left(BinaryTree& tree) { root->left = tree.root; }
        void add_right(BinaryTree& tree) { root->right = tree.root; }
        // Breadth first search (recorrido en anchura)
        void bfs(std::function<void (TipoDato&)> action) const{
            Queue Q;
            Q.push(*root);
            while(!Q.empty()){
                ElementoArbolBinario e=Q.front();
                Q.pop();
                action(e.dato);
                if (e.left) { Q.push(*e.left);}
                if (e.right) { Q.push(*e.right);}
            }
        }
};

#endif // BINARYTREE_H
