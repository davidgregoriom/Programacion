#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <set>
#include <functional>

using namespace std;

int main(){
    auto mostrar = [] (int x){
        cout << x << "\n";
    };
    auto mostrarPares= [] (int x){
      if(x%2==0){
        cout << x << "\n";
      }
    };
    auto mostrarTriple = [] (int x){
        cout << 3*x << "\n";
    };
    auto forEach = [](function<void(int)> g, vector<int> const & v){
        for(auto elem: v) g (elem);
    };
    vector<int>miVector{1,2,3,4,5};

    forEach(mostrar,miVector);
    forEach(mostrarPares,miVector);
    forEach(mostrarTriple,miVector);
}

