#include <iostream>
#include <vector>
#include <map>
using std::cout;
using std::map;
using std::vector;
bool suma(const vector<int> &values, int target, map<int, bool> &cachedInformation)
{
    auto value = cachedInformation.find(target);
    if (value != cachedInformation.end())
        return (value->second);
    if (target ==0) return (true);
    if (target <0) return (false);
    for (auto element:values){
        auto reminder = target-element;
        if (suma(values,reminder, cachedInformation)){
            cachedInformation.emplace(reminder,true);
            return (true);
        }

    }
        cachedInformation.emplace(target,false);
        return false;

}

int main()
{
    auto cache = map<int, bool>{};
    auto coleccion = vector<int>{ 10,7, 5};
    cout << suma(coleccion, 15, cache);
    return 0;
}
