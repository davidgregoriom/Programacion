#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <set>
#include <functional>

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
    
    vector<int>miVector{1,2,3,4,5};
    vector<int>modificado;
    
    forEach(v, [&] (int x){
    	if(x% 2 ==0) modificado.push_back(3*x);
    	});
    	

}
