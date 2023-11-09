#include <memory>
#include <iostream>

using namespace std;

struct ElementoArbolBinario {
   int dato;
   std::shared_ptr<ElementoArbolBinario> left = nullptr;
   std::shared_ptr<ElementoArbolBinario> right = nullptr;
    ElementoArbolBinario(int d) : dato{d} {}
};


class ABB {
   public:
       ABB() {}

       bool addElement(int dato) {
           return _addElement(_root, dato);
       }

       bool removeElement(int dato) {
           // Tú código comienza aquí
        auto elemento=_root;
        shared_ptr<ElementoArbolBinario> padre = nullptr;
        while(elemento!= nullptr){

        if(elemento->dato==dato){
            break;
        }
        padre= elemento;
        elemento= (dato<elemento ->dato)? elemento->left: elemento->right;
        }

        if(elemento->left!=nullptr&&elemento->right!=nullptr){
        padre==elemento;
        elemento= elemento->left;
        while(elemento->right!= nullptr){
            padre= elemento;
            elemento= elemento->right;

        }
        }

        auto siguiente= (elemento->left != nullptr)?elemento->left:elemento->right;
        if(padre==nullptr){
            _root= siguiente;
        }else{
            if(padre->left==nullptr){
                padre->left==siguiente;
            }else{
                padre->right==siguiente;
            }
        }
        if(elemento==nullptr){

           return false; // Devuelve si el elemento ha sido eliminado o no se encontró
        }

       }


   protected:
       bool _addElement(std::shared_ptr<ElementoArbolBinario>& node, int dato) {
           auto elem = std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
           if (!node) {
               node = elem;
               return true;
           }

           if (node->dato > dato) {
               return _addElement(node->left, dato);
           }
           else if (node->dato < dato) {
               return _addElement(node->right, dato);
           }
           else {
               return false; // Duplicated!
           }
       }

       std::shared_ptr<ElementoArbolBinario> _root = nullptr;
};

int main() {
   ABB tree;
   tree.addElement(1);
   tree.addElement(2);
   tree.addElement(3);
   tree.addElement(5);
   tree.addElement(8);
   tree.addElement(11);

   bool remove4 = tree.removeElement(4);
   bool remove5 = tree.removeElement(5);

   std::cout << "Element 4 was removed: " << std::boolalpha << remove4 << std::endl;
   std::cout << "Element 5 was removed: " << std::boolalpha << remove5 << std::endl;

}
