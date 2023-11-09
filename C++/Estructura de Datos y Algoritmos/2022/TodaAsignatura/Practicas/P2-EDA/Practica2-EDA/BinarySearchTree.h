#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "Wrapper.h"
#include <iostream>

/*
   Estructuras de Datos y Algoritmos
   Práctica II

   Alumnos:
    * Alejandro Riego Velasco
    * Jesus Cuesta Bartolomé
*/

using namespace std;

template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinarySearchTreeWithRank;

template <class Comparable>
class BinaryNode
{
    Comparable  element;
    BinaryNode *left;
    BinaryNode *right;
    int size;


    void printPreOrder( ) const;
    void printPostOrder( ) const;
    void printInOrder( ) const;


    BinaryNode( const Comparable & theElement, BinaryNode *lt,
                BinaryNode *rt, int sz = 0 )
      : element( theElement ), left( lt ), right( rt ), size( sz ) { }

    friend class BinarySearchTree<Comparable>;
    friend class BinarySearchTreeWithRank<Comparable>;
};


// BinarySearchTree class
//
// CONSTRUCTION: with no parameters or another BinarySearchTree.
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// void removeMin( )      --> Remove smallest item
// Comparable find( x )   --> Return item that matches x
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Exceptions are thrown by insert, remove, and removeMin if warranted

template <class Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( );
    BinarySearchTree( const BinarySearchTree & rhs );
    virtual ~BinarySearchTree( );



    void printPreOrder( ) const                                                   //FORMAS DE IMPRIMIR LOS ARBOLES
      { if ( root != NULL ) root->printPreOrder( ); }
    void printInOrder( ) const
      { if ( root != NULL ) root->printInOrder( ); }
    void printPostOrder( ) const
      { if ( root != NULL ) root->printPostOrder( ); }




    Cref<Comparable> findMin( ) const;
    Cref<Comparable> findMax( ) const;
    Cref<Comparable> find( const Comparable & x ) const;
    bool isEmpty( ) const;

    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );
    void removeMin( );


                                                                                                     //FUNCIONES A IMPLEMENTAR

    void removeMax();//Añadimos el método remove max
    int size();//Método que muestra el tamaño del BST
    void removeLessThan(const Comparable & x ); 
    void prune();
    void next(const Comparable & x );



    const BinarySearchTree & operator=( const BinarySearchTree & rhs );

    typedef BinaryNode<Comparable> Node;

  protected:
    Node *root;

    Cref<Comparable> elementAt( Node *t ) const;
    virtual void insert ( const Comparable & x, Node * & t ) const;
    virtual void remove( const Comparable & x, Node * & t ) const;
    virtual void removeMin( Node * & t ) const;
    Node * findMin( Node *t ) const;
    Node * findMax( Node *t ) const;
    Node * find( const Comparable & x, Node *t ) const;
    void makeEmpty( Node * & t ) const;
    Node * clone( Node *t ) const;


                                                                                                 //FUNCIONES A IMPLEMENTAR

    int treeSize( Node *t ) const
      { return t == NULL ? 0 : t->size; }

    void removeMax( Node * & t ) const; //Añadimos el método remove max

    BinaryNode<Comparable>* removeLessThan( Node * & t,const Comparable & x); //Metodo remove less than

    BinaryNode<Comparable>* prune(Node * & t);

    void next( Node * & t,const Comparable & x);

};




// BinarySearchTreeWithRank class.
//
// CONSTRUCTION: with no parameters or
//    another BinarySearchTreeWithRank.
//
// ******************PUBLIC OPERATIONS*********************
// Comparable findKth( k )--> Return kth smallest item
// All other operations are inherited (but C++ requires 
// some extra stuff).

template <class Comparable>
class BinarySearchTreeWithRank : public BinarySearchTree<Comparable>    //OTRO TIPO DE ARBOL
{
  public:
    Cref<Comparable> findKth( int k ) const;

    void insert( const Comparable & x )
      { BinarySearchTree<Comparable>::insert( x ); }
    void remove( const Comparable & x )
      { BinarySearchTree<Comparable>::remove( x ); }
    void removeMin( )
      { BinarySearchTree<Comparable>::removeMin( ); }

    typedef BinaryNode<Comparable> Node;

  private:
    void insert( const Comparable & x, Node * & t )const;
    void remove( const Comparable & x, Node * & t )const;
    void removeMin( Node * & t ) const;
    Node *findKth( int k, Node *t ) const;

    int treeSize( Node *t ) const
      { return t == NULL ? 0 : t->size; }
};

//-------------------------------------------------------------------------------------------------------------------------------------------

//FUNCIONES A IMPLEMENTAR (DESAROLLO)

template <class Comparable>
void BinarySearchTree<Comparable>::removeMax()      //RemoveMax PUBLICO
{
    removeMax(root);
}


template <class Comparable>
void BinarySearchTree<Comparable>::removeMax(Node*& t) const //RemoveMax PRIVADO
{
    if (t == NULL)
        throw UnderflowException();
    else if (t->right != NULL)
        removeMax(t->right);
    else
    {
        Node* tmp = t;
        t = t->left;
        delete tmp;
        return;
    }
    t->size--;
}


template <class Comparable>
int BinarySearchTree<Comparable>::size() //Muestra el tamaño de forma eficiente
{
    return treeSize( root );

}


template <class Comparable>
void BinarySearchTree<Comparable>::removeLessThan(const Comparable & x){
    root=removeLessThan(root,x);
}


template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::removeLessThan( Node * & t,const Comparable & x){
if (t == NULL){
   return NULL;
}

t->left =  removeLessThan(t->left, x);
t->right =  removeLessThan(t->right, x);

if (t->element < x)
{
    Node *right = t->right;
    delete t;
    root->size--;

    return right;
}
return t;
}


template <class Comparable>
void BinarySearchTree<Comparable>::prune(){ //PODAR PUBLICO
    prune(root);
}


template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::prune(Node * & t){ //PODAMOS LAS HOJAS
    if (t == NULL){
        return NULL;
    }

    if (t->left == NULL && t->right == NULL) {
        root->size--;
        delete t;
        return NULL;
    }

    t->left = prune(t->left);
    t->right = prune(t->right);

    return t;
}


template <class Comparable>
void BinarySearchTree<Comparable>::next(const Comparable & x){ //NEXT PUBLICO
    next(root,x);
}


template <class Comparable>
void BinarySearchTree<Comparable>::next( Node * & t,const Comparable & x){ //MUESTRA EL SIGUIENTE ELEMENTO A IZQ O DCHA

    Node *aux=find(x,t);

    if (aux->left!=NULL){
        cout<<"El siguiente elemento a la izquierda de "<<x<<" es: "<<aux->left->element<<endl;
    }
   if (aux->right!=NULL){
        cout<<"El siguiente elemento a la derecha de "<<x<<" es: "<<aux->right->element<<endl;
    }

    aux=NULL;
    delete aux;
}


//PARA IMPRIMIR LOS ÁRBOLES
template <class Object>
void BinaryNode<Object>::printPreOrder( ) const
{
    cout << element << endl;                  // Node
    if( left != NULL )
        left->printPreOrder( );               // Left
    if( right != NULL )
        right->printPreOrder( );              // Right
}


// Print the tree rooted at current node using postorder traversal.
template <class Object>
void BinaryNode<Object>::printPostOrder( ) const
{
    if( left != NULL )                        // Left
        left->printPostOrder( );
    if( right != NULL )                       // Right
        right->printPostOrder( );
    cout << element << endl;                  // Node
}


// Print the tree rooted at current node using inorder traversal.
template <class Object>
void BinaryNode<Object>::printInOrder( ) const
{
    if ( left != NULL )                        // Left
        left->printInOrder( );
    cout << element << endl;                  // Node
    if ( right != NULL )
        right->printInOrder( );               // Right
}


#include "BinarySearchTree.cpp"
#endif
