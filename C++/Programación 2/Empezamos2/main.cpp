#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <functional>

using namespace std;
shared_ptr<vector<int>> filter (vector<int>const & v,function<bool(int)>g){
        shared_ptr<vector<int>> presult = make_shared<vector<int>>();
        for(auto elem: v){
            if(g(elem))presult->push_back(elem);
        }
        return presult;
}
int main(){

       unique_ptr<int>pa = make_unique<int>(3);


}
