#include "iostream"
#include <functional>
#include <vector>
#include "memory"

using namespace std;

class TipoDato{
    public:
        std::string dato;
        //int dato; ES INT O STRING
};








class ElementoArbol {
    public:
        // Members
        TipoDato dato;
        std::vector<std::shared_ptr<ElementoArbol>> children;

        std::shared_ptr<ElementoArbol> left = nullptr;
        std::shared_ptr<ElementoArbol> right = nullptr;


    public:
        // Constructor
        ElementoArbol(const TipoDato& dato_) : dato{dato_} {};
};


class Tree {

    protected:
        std::shared_ptr<ElementoArbol> root = nullptr;
    public:
        Tree();  // Creates empty tree
        Tree(const TipoDato& dato);  // Creates tree with root node
        //void add_subtree(const Tree& subtree);
        void dfs_postorder(std::function<void (TipoDato&)> action) const;
        void dfs_inorder(std::function<void (TipoDato&)> action) const;

        void add_left(const Tree& subtree);
        void add_right(const Tree& subtree);

        void _print_infix() const;
    friend std::ostream& operator<<(std::ostream& os, const Tree& e);
private:
        std::string a;


};
std::ostream& operator<<(std::ostream& os, const Tree& e);

// LO DE ABAJO NO SABEMOS SI ESTA BIEN
Tree::Tree(const TipoDato& dato) {
    root = std::make_shared<ElementoArbol>(ElementoArbol{dato});
}
std::ostream& operator<<(std::ostream& os, const Tree& empleado){
    os << empleado.root<<endl;
    return os;
}
void Tree::add_left(const Tree& subtree) {
    root->left = subtree.root;
}

void Tree::add_right(const Tree& subtree) {
    root->right = subtree.root;
}
// HASTA AQUI
void print_infix(std::shared_ptr<ElementoArbol> root) {
    if (!root->children.empty()) {
        print_infix(root->children[0]);
    }
    std::cout << root->dato;

    for (int i=1; i<root->children.size(); i++) {
        print_infix(root->children[i]);
    }
}

void Tree::_print_infix() const {
    print_infix(root);
}


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

void _dfs_inorder(std::shared_ptr<ElementoArbol> root,
                  std::function<void (TipoDato&)> action) {
    if (!root->children.empty()) {
        _dfs_inorder(root->children[0], action);
    }
    action(root->dato);

    for (int i=1; i<root->children.size(); i++) {
        _dfs_inorder(root->children[i], action);
    }

}

void Tree::dfs_inorder(std::function<void (TipoDato&)> action) const {
    _dfs_inorder(root, action);
}




int main() {
    // Expresion "3 + 4"
    Tree arbol{TipoDato{"+"}};
    arbol.add_left(TipoDato{"3"});
    arbol.add_right(TipoDato{"4"});



    std::cout << "Hola\n";

    // Notación infija
    arbol.dfs_inorder([] (const TipoDato& dato) {
        std::cout << "ENTRA EN dfs_inorder" << endl;
        std::cout << dato.dato << endl;

            return dato;


    });



    // Notación postfija
    arbol.dfs_postorder([](const TipoDato& dato) {
        std::cout << "ENTRA EN dfs_postorder" << endl;
        return dato;
    });
}
