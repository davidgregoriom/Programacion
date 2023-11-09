#include "binarysearchtree.h"
using namespace std;


BinarySearchTree::BinarySearchTree(){

}

void _push(shared_ptr<ElementoArbolBinario> element, const Empleado& dato){
    if(element == nullptr){
        element = make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
        return;
    }
    if(element->dato < dato){
        _push(element->left, dato);
    }else if(element->dato < dato){
        _push(element->right, dato);
    }else{
        cout << "ID duplicada. Intentalo de nuevo" << endl;
    }
}

void BinarySearchTree::push(const Empleado &dato)
{
    return _push(root, dato);
}

int _size(std::shared_ptr<ElementoArbolBinario> element) {
    if (element == nullptr) {
        return 0;
    }
    else {
        int size_left = _size(element->left);
        int size_right = _size(element->right);
        return 1 + size_left + size_right;
    }
}

int BinarySearchTree::size() const
{
    return _size(root);
}

void for_each(shared_ptr<ElementoArbolBinario>root, function<void(Empleado&)> action) {
    //dfs_inorder
    if(root->left != nullptr) {
        for_each(root->left, action);
    }
    action(root->dato);

    if(root->right != nullptr) {
        for_each(root->right, action);
    }
}
void BinarySearchTree::for_each(std::function<void (Empleado &)> action) const{
    //dfs_inorder
    for_each(action);
}





const Empleado &_find(std::shared_ptr<ElementoArbolBinario> element, const Empleado& dato) {
    // Handle corner case
    if (element == nullptr) {
        return dato;
    }
    if (element->dato > dato) {
        return _find(element->left, dato);
    }
    else if (element->dato < dato) {
        return _find(element->right, dato);
    }
    else {
        return element->dato = dato;
    }
}
const Empleado &BinarySearchTree::find(int id) const
{
    return _find(root, root-> dato);
}

