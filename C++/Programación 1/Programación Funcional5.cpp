#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <set>
#include <functional>
#include <complex>

using namespace std;

int main(){


    auto forEach = [](function<void(int)> g, vector<int> const & v){
        for(auto elem: v) g (elem);
    };

    auto transform =  [](vector<int>const & v,function<int(int)>g){
        vector<int> result;
        for(auto elem: v){
            result.push_back(g(elem));
        }
        return result;
    };
    auto filter =  [](vector<int>const & v,function<bool(int)>g){
        vector<int> result;
        for(auto elem: v){
            if(g(elem))result.push_back(elem);
        }
        return result;
    };

     auto restos = [](int x){
        return x%2;
    };
    vector<int>miVector{1,2,3,4,5};




    auto mostrar =[](int z){
        cout<< z << "\n";
    };
    auto doble=[](int x){
        return 2*x;
    };



    auto resultado1 = filter(miVector, restos);
    for(auto elem: resultado1){
      cout << elem << " - ";
    }
    cout<< "\n";

    auto resultado = transform(miVector, doble);
        for(auto elem: resultado){
          cout << elem << " - ";
        }


}

