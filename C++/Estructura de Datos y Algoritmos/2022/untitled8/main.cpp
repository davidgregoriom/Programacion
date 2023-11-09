// Fibonnaci programación dinámica y "tradicional"
#include <iostream>
using namespace std;

/**
 * Compute Fibonacci numbers as described in Chapter 1.
 */
long long fib( int n )
{
    if( n <= 1 )
        return 1;
    else
        return fib( n - 1 ) + fib( n - 2 );
}

/**
 * Compute Fibonacci numbers as described in Chapter 1.
 */
long long fibonacci( int n )
{
    if( n <= 1 )
        return 1;

    long long last = 1;
    long long nextToLast = 1;
    long long answer = 1;

    for( int i = 2; i <= n; ++i )
    {
        answer = last + nextToLast;
        nextToLast = last;
        last = answer;
    }
    return answer;
}

int main( )
{
    cout << "fib( 20 ) = " << fib( 20 ) << endl;
    cout << "fibonacci( 20 ) = " << fibonacci( 20 ) << endl;
    return 0;
}
