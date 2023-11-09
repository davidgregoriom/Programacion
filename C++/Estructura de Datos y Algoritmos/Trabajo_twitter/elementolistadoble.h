#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include "librerias.h"

using namespace std;

#include <string>
#include <memory>
#include <functional>


class ElementoArbolBinario {
    public:
        // Members
        std::string dato;  // Will contain a number or a math symbol
        std::shared_ptr<ElementoArbolBinario> left = nullptr;
        std::shared_ptr<ElementoArbolBinario> right = nullptr;
    public:
        // Constructor
        ElementoArbolBinario(const std::string& dato_) : dato{dato_} {};
};


class BinaryTree {
    private:
        std::shared_ptr<ElementoArbolBinario> root = nullptr;

    public:
        BinaryTree(const std::string& dato);

        void add_left(const BinaryTree&);
        void add_right(const BinaryTree&);

        void dfs_inorder(std::function<void (const std::string&)> action) const;
        void dfs_postorder(std::function<void (const std::string&)> action) const;
};
class Empleado {
    public:
        Empleado(int id, bool is_boss);

        int get_id() const;
        bool is_boss() const;

        bool operator<(const Empleado& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Empleado& empleado);
    private:
        int id_;
        bool is_boss_;
};
#endif // ELEMENTOLISTADOBLE_H
