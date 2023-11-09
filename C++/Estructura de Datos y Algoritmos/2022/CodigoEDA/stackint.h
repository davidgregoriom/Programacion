#ifndef STACKLI_H_
#define STACKLI_H_

#include <stdlib.h>
#include "except.h"


// Stack class -- linked list implementation.
//
// CONSTRUCTION: with no parameters.
//
// ******************PUBLIC OPERATIONS*********************
// void push( x )        --> Insert x
// void pop( )           --> Remove most recently inserted item
// Object top( )         --> Return most recently inserted item
// Object topAndPop( )   --> Return and remove most recently inserted item
// bool isEmpty( )       --> Return true if empty; else false
// void makeEmpty( )     --> Remove all items
// ******************ERRORS********************************
// UnderflowException thrown as needed.

class StackInt
{
  public:
    StackInt( );
    StackInt( const StackInt & rhs );
    ~StackInt( );

    bool isEmpty( ) const;
    const int & top( ) const;

    void makeEmpty( );
    void pop( );
    void push( const int & x );
    int topAndPop( );

    const StackInt & operator=( const StackInt & rhs );

  private:
    struct ListNode
    {
        int    element;
        ListNode *next;

        ListNode( const int & theElement, ListNode * n = nullptr)
          : element( theElement ), next( n ) { }
    };

    ListNode *topOfStack;
};

#endif
