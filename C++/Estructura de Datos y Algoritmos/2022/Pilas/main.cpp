#include <iostream>
#include <exception>

using namespace std;
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

template <class Object>
class Stack
{
public:
    Stack( );
    Stack( const Stack & rhs );
    ~Stack( );

    bool isEmpty( ) const;
    const Object & top( ) const;

    void makeEmpty( );
    void pop( );
    void push( const Object & x );
    Object topAndPop( );

    const Stack & operator=( const Stack & rhs );

private:
    struct ListNode
    {
        Object    element;
        ListNode *next;

        ListNode( const Object & theElement, ListNode * n = NULL )
            : element( theElement ), next( n ) { }
    };

    ListNode *topOfStack;
};
// Construct the stack.
template <class Object>
Stack<Object>::Stack( )
{
    topOfStack = NULL;
}

// Copy constructor.
template <class Object>
Stack<Object>::Stack( const Stack<Object> & rhs )
{
    topOfStack = NULL;
    *this = rhs;
}

// Destructor.
template <class Object>
Stack<Object>::~Stack( )
{
    makeEmpty( );
}

// Test if the stack is logically empty.
// Return true if empty, false, otherwise.
template <class Object>
bool Stack<Object>::isEmpty( ) const
{
    return topOfStack == NULL;
}

// Make the stack logically empty.
template <class Object>
void Stack<Object>::makeEmpty( )
{
    while( !isEmpty( ) )
        pop( );
}

// Return the most recently inserted item in the stack.
// or throw an UnderflowException if empty.
template <class Object>
const Object & Stack<Object>::top( ) const
{
    if( isEmpty( ) )
        throw UnderflowException( );
    return topOfStack->element;
}

// Remove the most recently inserted item from the stack.
// Throw Underflow if the stack is empty.
template <class Object>
void Stack<Object>::pop( )
{
    if( isEmpty( ) )
        throw UnderflowException( );

    ListNode *oldTop = topOfStack;
    topOfStack = topOfStack->next;
    delete oldTop;
}

// Return and remove the most recently inserted item
// from the stack.
template <class Object>
Object Stack<Object>::topAndPop( )
{
    Object topItem = top( );
    pop( );
    return topItem;
}

// Insert x into the stack.
template <class Object>
void Stack<Object>::push( const Object & x )
{
    topOfStack = new ListNode( x, topOfStack );
}

// Deep copy.
template <class Object>
const Stack<Object> & Stack<Object>::operator=( const Stack<Object> & rhs )
{
    if( this != &rhs )
    {
        makeEmpty( );
        if( rhs.isEmpty( ) )
            return *this;

        ListNode *rptr = rhs.topOfStack;
        ListNode *ptr  = new ListNode( rptr->element );
        topOfStack = ptr;

        for( rptr = rptr->next; rptr != NULL; rptr = rptr->next )
            ptr = ptr->next = new ListNode( rptr->element );
    }
    return *this;
}

int main(){
    cout << "Hello World!" << endl;
    return 0;
}
