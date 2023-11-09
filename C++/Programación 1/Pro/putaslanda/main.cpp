#include <iostream>
#include <functional>
#include<array>
#include<vector>

using namespace std;

function<int(vector<int>)> media = [] (vector<int>v) {
    float suma{0};

};

function<int (int, int) > resta = [] (int a, int b) {
    return a - b;
};
function<int (int, int) > multiplicacion = [] (int a, int b) {
    return a * b;
};
function<int (int, int) > division = [] (int a, int b) {
    return a / b;
};

function<void(function<int(int,int)>, int, int)> print = [] (function<int(int,int)>f, int a, int b){
    cout << f(a,b) << "\n";
};


int main() {
    cout <<"Introduce un numero del 0 al 3\n";
    int opcion;
    cin>> opcion;
    cout <<"Introduce dos numeros \n";
    int a,b;
    cin>> a >>b;
    array< function<int(int,int)>,4>operacion{suma,resta,multiplicacion,division};
    cout << operacion.at(opcion)(a,b);
    return 0;
}
