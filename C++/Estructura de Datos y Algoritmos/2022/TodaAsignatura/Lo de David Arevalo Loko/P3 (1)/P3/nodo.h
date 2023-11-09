#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <memory>

using namespace std;

class nodo{
    public:
        nodo(int d);

        int getDato() const;
        void setDato(int value);

        shared_ptr<nodo> getRight() const;
        void setRight(const shared_ptr<nodo> &value);

        shared_ptr<nodo> getLeft() const;
        void setLeft(const shared_ptr<nodo> &value);

        void inorder(shared_ptr<nodo> root);
        void postorder(shared_ptr<nodo> root);
        void preorder(shared_ptr<nodo> root);
        void pushnodo(shared_ptr<nodo> root, int valor);

        bool nodovacio(shared_ptr<nodo> root);
        bool numpremiado(shared_ptr<nodo> root,int valor);

    private:
        int dato;
        shared_ptr<nodo> right;
        shared_ptr<nodo> left;
};

#endif // NODO_H