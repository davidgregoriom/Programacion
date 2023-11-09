#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {
    int numero;
    vector<int>multiplos;
    while( numero<=100){
        if(numero % 6== 0){
            multiplos.push_back(numero);
        }
        numero++;
    }
    for(auto elem:multiplos){
        cout<<elem ;
    }
 }
