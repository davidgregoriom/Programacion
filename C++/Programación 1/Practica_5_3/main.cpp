#include <iostream>
#include <complex>
#include<functional>

using namespace std;

int main()
{
 complex<float>numero1{1,2};
 complex<float>numero2{2,3};
 auto suma = [&](complex<float>r,complex<float>s){
     return r + s;

 };
 auto resta = [&](complex<float>r,complex<float>s){
     return r - s;

 };
 auto multi = [&](complex<float>r,complex<float>s){
     return r * s;

 };
 auto print=[] (function<float(complex<float>)>const & a, complex<float>e ){
        cout <<a(e) << "\n";

    };

    function<float(function<float(complex<float>)>, function<float(complex<float>)>, complex<complex<float>)> comp = [] (function<float(complex<float>)> f, function<float(complex<float>)> h, complex<complex<float>> v){
        complex<float>g;
        for(auto v: v){
            g.push_back(h(v));
        }
        return f(g);

    };
}
