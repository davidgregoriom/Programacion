#include <iostream>
#include <functional>
#include <vector>

using namespace std;


vector<int> filter(vector<int> const & vec, function< bool (int)> const & op){
    vector<int> result;
    for(auto elem:vec){
        if(op(elem)) result.push_back(elem);

    }
    return result;
}

int main(){

     vector<int> myVector{0,1,0,2,3,4,5};

     vector<int> result1 = filter(myVector, [](int e) ->bool {
         return e > 3;
     });
     vector<int> result2 = filter(myVector, [](int e) ->bool {
         return (e % 2 == 0);
     });
     vector<int> result3 = filter(myVector, [](int e) ->bool {
         return (e== 0);
     });
     cout << "Hay " <<result3.size() << "elementos con 0 de valor\n";
     return 0;
}


