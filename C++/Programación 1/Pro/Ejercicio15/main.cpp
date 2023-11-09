#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

int main()
{
    vector<int> vec {1,2,3,4,5,6,7,8,9,0};
    vector<int> par;


    int pos{0};
    while(pos < vec.size()){
        if(vec.at(pos) %2 == 0){
            par.push_back(vec.at(pos));
        }
        pos++;
    }



}
