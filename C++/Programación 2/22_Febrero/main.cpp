#include <iostream>
#include "complejo.h"
using namespace std;

Complejo sumar(Complejo a, Complejo b){
    Complejo result;
    result.setA((a.getA())+(b.getA()));
    result.setB((a.getB())+(b.getB()));
    return result;
}
Complejo Multiplica(Complejo a, Complejo b){
    Complejo result;
    result.setA((a.getA()*b.getA())+(a.getB()*b.getB()));
    result.setB((a.getA()*b.getB())+(a.getB()*b.getA()));
    return result;
}
int main()
{
    Complejo uno = Complejo(1,2);
    Complejo dos = Complejo(2,3);

    Complejo sum = sumar(uno,dos);
    Complejo mult = Multiplica(uno,dos);
    cout << sum.getA() << ",";
    cout << sum.getB() <<endl;
    cout << mult.getA() << ",";
    cout << mult.getB() << endl;
}
