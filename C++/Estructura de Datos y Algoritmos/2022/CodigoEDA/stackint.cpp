#include "stackint.h"

//Costrulle la pila
StackInt::StackInt()
{
    topOfStack =nullptr;
}
//Copia constructor
StackInt::StackInt(const StackInt &rhs)
{
    topOfStack = nullptr;
       *this = rhs;
}
//Destrulle la pila
StackInt::~StackInt()
{
    makeEmpty( );
}
//Testea si la pila esta vacia
//Si esta vacia devuelve un true,en caso constrario un false
bool StackInt::isEmpty() const
{
    return(topOfStack==nullptr);
}
//Devuelve la mayor reciente inseccion item en la pila
//o lanza una escepcion llamada UnderflowException si esta vacia
const int &StackInt::top() const
{
    if( isEmpty( ) ) throw UnderflowException( );
        return topOfStack->element;
}
//Hace la pila vacia
void StackInt::makeEmpty()
{
    while( !isEmpty( ) )
            pop( );
}
//Remueve la mayor reciente inseccion item en la pila
//o lanza una escepcion llamada UnderflowException si esta vacia
void StackInt::pop()
{
    if( isEmpty( ) )throw UnderflowException( );
    ListNode *oldTop = topOfStack;
    topOfStack = topOfStack->next;
    delete oldTop;
}

//Inserto x dentro de la pila
void StackInt::push(const int &x)
{
     topOfStack= new ListNode(x,topOfStack);
}

//Devuelvo y remuevo la mayor reciente inseccion item en la pila
int StackInt::topAndPop()
{
    int topItem = top( );
    pop( );
    return topItem;
}
//Copia profunda
const StackInt &StackInt::operator=( const StackInt & rhs )
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
