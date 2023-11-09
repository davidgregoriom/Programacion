#include "BinarySearchTree.h"

#ifdef USE_DOT_H
    #include <iostream.h>
#else
    #include <iostream>
    using namespace std;
#endif

/*
   Estructuras de Datos y Algoritmos
   Práctica II

   Alumnos:
    * Alejandro Riego Velasco
    * Jesus Cuesta Bartolomé
*/



int main( )
{
    BinarySearchTree<int> t1,t2;

    t1.insert(1);t1.insert(2);t1.insert(3);t1.insert(4);t1.insert(5);t1.insert(6);
    t1.insert(-1);t1.insert(-2);t1.insert(-3);t1.insert(-4);t1.insert(-5);t1.insert(-6);

    //t1.insert(5);t1.insert(2);t1.insert(1);t1.insert(3);t1.insert(12);t1.insert(9);t1.insert(21);t1.insert(19);t1.insert(25);


      //IMPRIMIRLO PARA VER SI SE RELLENA BIEN
    cout<<"TAMANO"<<endl;
    cout<<t1.size()<<endl;
    cout<<endl;
    cout<<"INORDER"<<endl;
    t1.printInOrder();
    cout<<endl;
    cout<<endl;



    /* //PROBAR PRUNE
    cout<<"TAMANO"<<endl;
    cout<<t1.size()<<endl;
    cout<<endl;
    cout<<"CORTAMOS LAS HOJAS"<<endl;
    t1.prune();
    cout<<endl;
    cout<<"TAMANO"<<endl;
    cout<<t1.size()<<endl;
    cout<<endl;
    cout<<"INORDER"<<endl;
    t1.printInOrder();
    cout<<endl;
    cout<<endl;
    */


    /* //PROBAR NEXT
    t1.next(1);
    cout<<endl;
    cout<<endl;
    */


    /* //PROBAR REMOVE MAX
    cout<<"QUITAMOS EL MAXIMO"<<endl;
    t1.removeMax();
    cout<<endl;
    cout<<"INORDER"<<endl;
    t1.printInOrder();
    cout<<endl;
    */


    /*
     //PROBAR REMOVE LESS THAN
    cout<<"QUITAMOS LOS ELEMENTOS MENORES QUE X"<<endl;
    t1.removeLessThan(0);
    cout<<"TAMANO"<<endl;
    cout<<t1.size()<<endl;
    cout<<endl;
    cout<<"INORDER"<<endl;
    t1.printInOrder();
    cout<<endl;
    cout<<endl;
*/

    cout<<"-------------------------------------------"<<endl;

    /*
    cout<<"PREORDER"<<endl;
    t1.printPreOrder();
    cout<<"INORDER"<<endl;
    t1.printInOrder();
    cout<<"POSTORDER"<<endl;
    t1.printPostOrder();
    cout<<endl;
    */

    return 0;
}
