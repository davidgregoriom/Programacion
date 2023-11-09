#include <iostream>
#include <vector>

using namespace std;

float media(vector<float> const & m1){
    float m{0};
    for(auto elem : m1){
        m+=elem;
    }
    return m / m1.size();
};

int main(){


    return 0;
}


