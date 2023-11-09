#include "nodo.h"

using namespace std;

nodo::nodo(int d){
    this->dato = d;
    this->left = this->right = nullptr;
}

int nodo::getDato() const{
    return dato;
}

void nodo::setDato(int value){
    dato = value;
}

shared_ptr<nodo> nodo::getRight() const{
    return right;
}

void nodo::setRight(const shared_ptr<nodo> &value){
    right = value;
}

shared_ptr<nodo> nodo::getLeft() const{
    return left;
}

void nodo::setLeft(const shared_ptr<nodo> &value){
    left = value;
}

void nodo::inorder(shared_ptr<nodo> root){
    if (root == nullptr) {
        return;
    }
    inorder(root->getLeft());
    cout << root->getDato() << " ";
    inorder(root->getRight());
}

void nodo::postorder(shared_ptr<nodo> root){
    if (root == nullptr) {
        return;
    }

    postorder(root->getLeft());
    postorder(root->getRight());
    cout << root->getDato() << " ";
}

void nodo::preorder(shared_ptr<nodo> root){
    if (root == nullptr) {
        return;
    }

    cout << root->getDato() << " ";
    preorder(root->getLeft());
    preorder(root->getRight());
}

void nodo::pushnodo(shared_ptr<nodo> root, int valor){
    root->setDato(valor);
}

bool nodo::nodovacio(shared_ptr<nodo> root){
    if (root == nullptr) {
        return false;
    }
    else if (root->getDato()== 0){
        return true;
    }
    nodovacio(root->getLeft());
    nodovacio(root->getRight());
}

bool nodo::numpremiado(shared_ptr<nodo> root, int valor){
    if (root == nullptr){
        return false;
    } 
    else if(root->getDato() == valor){
        return true;
    }
    numpremiado(root->getLeft(),valor);
    numpremiado(root->getRight(),valor);
}
