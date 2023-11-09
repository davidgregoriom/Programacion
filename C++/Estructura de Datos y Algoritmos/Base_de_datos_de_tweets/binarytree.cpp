#include "binarytree.h"
#include <algorithm>

BinaryTree::BinaryTree() {}

void BindInput( ifstream & inputChannel );

BinaryTree::BinaryTree( hashtags& datos) {

    string hastgs("/home/david/Desktop/Estructura de Datos y Algoritmos/Base_de_datos_de_tweets/Hastags");
    /*BindInput dato{hastgs};

    dato=datos;*/
}



int _height(std::shared_ptr<ElementoArbolBinario> element) {
    if (element == nullptr) {
        return -1;
    }
    else {
        int height_left = _height(element->left);
        int height_right = _height(element->right);
        return 1 + std::max(height_left, height_right);
    }
}

int BinaryTree::height() const {
    return _height(root);
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

int BinaryTree::size() const {
    return _size(root);
}


bool _find(std::shared_ptr<ElementoArbolBinario> element, const hashtags& dato) {
    // Handle corner case
    if (element == nullptr) {
            return false;
        }

        // Do actual work
        if (element->dato > dato) {
            return _find(element->left, dato);
        }

        else if (element->dato < dato) {
            return _find(element->right, dato);
        }
        else {
            return element->dato == dato;
        }
}

bool BinaryTree::find(const hashtags& dato) const {
    return _find(root, dato);
}
/*
 void _dfs_inorder(std::shared_ptr<ElementoArbolBinario> root, std::function<void (const std::string&)> action) {
        if (root->left != nullptr) {
            _dfs_inorder(root->left, action);
        }

        action(root->dato);

        if (root->right != nullptr) {
            _dfs_inorder(root->right, action);
        }
    }





void BinaryTree::dfs_inorder(std::function<void (const std::string&)> action) const {
    _dfs_inorder(root, action);
}
*/
const hashtags& _min(std::shared_ptr<ElementoArbolBinario> element) {
    if (element->left != nullptr) {
        return _min(element->left);
    }
    else {
        return element->dato;
    }
}

const hashtags& BinaryTree::min() const {
    return _min(root);
}
const hashtags& _max(std::shared_ptr<ElementoArbolBinario> element) {
    if (element->right != nullptr) {
        return _max(element->right);
    }
    else {
        return element->dato;
    }
}

const hashtags& BinaryTree::max() const {
    return _max(root);
}
void _push(shared_ptr<ElementoArbolBinario> element, const hashtags& dato){
    if(element == nullptr){
        element = make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
        return;
    }
    if(element->dato < dato){
        _push(element->left, dato);
    }else if(element->dato < dato){
        _push(element->right, dato);
    }else{

    }
}

void BinaryTree::push(const hashtags&dato)
{
    return _push(root, dato);
}

