#include <iostream>
#include<complex>
#include<functional>
using namespace std;
complex<float>op(function<complex<float>(complex<float> const &,complex<float> const &)> f, complex <float> const & a, complex<float> const & b){
    return f(a,b);
}


int main(){
    complex<float> numA;
    complex<float> numB;

    numA.real(5);
    numB.imag(4);

    numB.real(2);
    numA.imag(4);

    auto const & suma =[](complex<float>const & a, complex <float> const & b){
        return a+b;
    };
    auto const & resta =[](complex<float>const & a, complex <float> const & b){
        return a-b;
    };
    auto const & multiplicacion =[](complex<float>const & a, complex <float> const & b){
        return complex<float>{(a.real()*b.real()- a.imag()*b.imag()),0};
    };
    complex<float> lasuma= op(suma, numA, numB);
    complex<float> laresta= op(resta, numA , numB);
    complex<float> lamult = op(multiplicacion, numA , numB);
}
