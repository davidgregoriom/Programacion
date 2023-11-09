#include <iostream>
#include <memory>
#include <array>

using namespace std;
int main(){

    array <int> arr;
    for(int i {0};i<3;i++){
        arr.at(i)=i;
    }
    for(auto elem :arr){
        cout<<elem;
    }

}
