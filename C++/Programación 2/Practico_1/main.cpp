#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <memory>
#include <functional>
using namespace std;


shared_ptr<vector<int>>filter(vector<int>const & arr, function<bool(int)>f){
    shared_ptr<vector<int>> presult = make_shared<vector<int>>();
    for(auto elem :arr){
        if(f(elem)) presult->push_back(elem);
    }
   return presult;
}



int main()
{
    array<shared_ptr<int>,10> arr1;
    cout << "Hello World!" << endl;
    return 0;
}
