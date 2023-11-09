#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<int> for_each(vector<int> const & values,function<int (int)> const & f) {
    for(auto e :values){
        f(e);
    }
}
vector<int> for_each2(vector<int> const & values,function<void (int)> const & f) {
    for(auto e :values){
        f(e);
    }
}

int main() {
    vector<int> values{1, 3, 5, 8, 13};
    vector<int> results_1;
    auto output = for_each(values, [](int v){ return v*v;});
    auto output2= for_each2(values,[&](int v){
        if(v % 1== 1) results_1.push_back(v);
    });



}

