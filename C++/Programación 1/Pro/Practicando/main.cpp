#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main(){


    auto transform = [](vector<int>v, function<void(int)>g) {
        vector<int>result;
        for(auto elem:v){
            result.push_back(g(elem));
        }
        return result;
    };


    auto forEach = []( vector<int>const & v, function<void(int)>g){
        for(auto elem: v) g(elem);

    };
    vector<int> v{1,2,3,4,5,6};

    forEach(v,[=] (int x){
        if(x > max) max = x;
    });



}
