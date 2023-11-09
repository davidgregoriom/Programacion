#include <iostream>
#include <vector>
#include <map>

using namespace std;
bool suma(const vector<int> & values , int target, map<int,bool>& cacheInformation){
    auto value = cacheInformation.find(target);
    if(value != cacheInformation.end()){
        return(value->second);
    }
    if(target == 0) return (true);
    if(target <0) return (false);
    for (auto element:values){
        auto reminder = target-element;
        if(suma(values,reminder,cacheInformation)){
            cacheInformation.emplace(reminder,true);
            return (true);
        }

    }
    cacheInformation.emplace(target,false);
    return false;

}



int main() {
    auto cache = map<int, bool>{};
    auto coleccion = vector<int>{2,3,5};
    cout << suma(coleccion,12, cache);

}
