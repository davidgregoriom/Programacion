

#pragma once

#include <memory>
#include <functional>
#include "elementolistadoble.h"

using namespace std;

class BinarySearchTree {
    private:
        std::shared_ptr<ElementoArbolBinario> root = nullptr;

    public:
        BinarySearchTree();  // Creates empty tree

        void push(const Empleado&);

        int size() const; // Number of nodes
        void for_each(std::function<void (Empleado&)> action) const;  // Visit all the nodes
        const Empleado& find(int id) const; // Return the employee with the given id
};

