#include <iostream>
#include <memory>
#include <vector>
#include "nodo.h"

using namespace std;

void printBinaryTree(shared_ptr<nodo> root, int space = 0, int height = 10){
  // Base case
  if (root == nullptr) {
    return;
  }
  // increase distance between levels
  space += height;
  // print right child first
  printBinaryTree(root->getRight(), space);
  cout << endl;
  // print the current node after padding with spaces
  for (int i = height; i < space; i++) {
    cout << ' ';
  }
  cout << root->getDato();
  // print left child
  cout << endl;
  printBinaryTree(root->getLeft(), space);
}

int main(){
  vector<int> premiados;
  for(size_t i = 0; i < 10;i++){
    premiados.push_back((rand() % 100) + 1);
  }
  cout << "Imprimimos los Nodos \n";
  for(int elem: premiados){
    cout << elem << ", " ;
  }
  cout << endl << endl;

  cout << "Pintamos el arbolito \n";
  shared_ptr<nodo> raiz = make_shared<nodo>(1);
  raiz->setLeft(make_shared<nodo>(2));
  raiz->setRight(make_shared<nodo>(3));
  raiz->getLeft()->setRight(make_shared<nodo>(5));
  raiz->getLeft()->setLeft(make_shared<nodo>(4));
  raiz->getRight()->setLeft(make_shared<nodo>(6));
  raiz->getRight()->setRight(make_shared<nodo>(7));
  raiz->getLeft()->getLeft()->setLeft(make_shared<nodo>(8));
  raiz->getLeft()->getLeft()->setRight(make_shared<nodo>(9));
  raiz->getLeft()->getRight()->setLeft(make_shared<nodo>(10));

  raiz->pushnodo(raiz,premiados.at(0));
  raiz->pushnodo(raiz->getLeft(),premiados.at(1));
  raiz->pushnodo(raiz->getRight(),premiados.at(2));
  raiz->pushnodo(raiz->getLeft()->getLeft(),premiados.at(3));
  raiz->pushnodo(raiz->getLeft()->getRight(),premiados.at(4));
  raiz->pushnodo(raiz->getRight()->getLeft(),premiados.at(5));
  raiz->pushnodo(raiz->getRight()->getRight(),premiados.at(6));
  raiz->pushnodo(raiz->getLeft()->getLeft()->getLeft(),premiados.at(7));
  raiz->pushnodo(raiz->getLeft()->getLeft()->getRight(),premiados.at(8));
  raiz->pushnodo(raiz->getLeft()->getRight()->getLeft(),premiados.at(9));

  printBinaryTree(raiz);cout<<endl;

  cout << "Ordenamos los Nodos del arbol \n";
  cout << "IN-ORDER: "; raiz->inorder(raiz); cout<<endl;
  cout << "PRE-ORDER: ";raiz->preorder(raiz); cout<<endl;
  cout << "POST-ORDER: ";raiz->postorder(raiz); cout<<endl;

  //int a = raiz->numpremiado(raiz,59);
  //cout << a << endl;

  //int b = raiz->nodovacio(raiz->getLeft()->getRight()->getRight());
  //cout << b << endl;

  return 0;
}