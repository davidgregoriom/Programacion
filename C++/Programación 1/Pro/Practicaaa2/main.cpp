#include <iostream>
#include <array>
#include <vector>
#include <stdlib.h>

using namespace std;
array<int,10>hola(){
    array<int,10>fibonacci{0,1,0,0,0,0,0,0,0,0};
    for(int i{2};i<=9;i++){
        fibonacci.at(i)=fibonacci.at(i-2)+fibonacci.at(i-1);
    }
    for(auto elem:fibonacci){
        cout << elem;
    }
    cout <<"\n";
    return fibonacci;
}

int main(){
    array<int,10>mola;

    mola= hola();
}


