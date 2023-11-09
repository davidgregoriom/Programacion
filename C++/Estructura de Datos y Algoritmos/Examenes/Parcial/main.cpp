#include <iostream>
#include <vector>
#include "queue.h"
#include "elementlistasimple.h"


using namespace std;


const std::string key = "abcdefghijklmnopqrstuvwxyz" ;
std::string cipher_iterative(std::string str, int i) {
    std::string output;
    for ( char ch: str) {
        ch = ( char ) (key.at( 0 ) + (ch - key.at( 0 ) + i) % key.size());
        output.push_back(ch);
    }
    return output;
}
int pos(char c){
    for(int i{0}; i < key.size(); i++){
        if(c == key[i])return i;
    }
    return -1;
}

std::string cipher_recursive(std::string str, int i) {
    int posic{0};
    posic = pos(str.back());
    str.pop_back();
    return key[posic + i] + cipher_recursive(str, i);
}

float accumulate( float sum, std::vector< float > values) {
    if(values.size() == 1)return sum + values[0];
    sum+=values[values.size()-1];
    values.pop_back();
    return accumulate(sum, values);
}

void bubble_sort(std::vector<float>& desordenado) {
    for(int i{0}; i < desordenado.size() - 1; i++){
        for(int k{0}; k < desordenado.size() - 1; k++){
            if(desordenado[k]< desordenado[k+1])swap(desordenado[k], desordenado[k+1]);
                }
    }
    }

int main()
{
    std::string input = "estructurasdedatos" ;
    int shift = 1 ;
    std::cout << input << std::endl;
    std::cout << cipher_iterative(input, shift) << std::endl;
    //std::cout << cipher_recursive(input, shift) << std::endl;
    std::vector< float > values{ 2 , 3 , 5 , 8 };
        std::cout << accumulate( 0 , values) << std::endl;
}
