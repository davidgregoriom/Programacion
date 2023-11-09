#include <iostream>
#include<functional>
#include<vector>
using namespace std;

int main(){
vector<float>vector1;
vector<float>vector2;

//Criterio 1:
auto Parte1 = [&](vector<float> & A){
    int random ;
    int i =0;
    srand(time(NULL));
    random = rand()%100 + 0;
    if(random%2==0){
        A.at(i)= random;
        i++;
    }
    return A;
};

//Criterio 2:
auto Parte2 = [&](vector<float>  & B){
    int random ;
    int i =0;
    srand(time(NULL));
    random = rand()%100 + 0;
    if(random%2==0 & random%3==0 & random <20){
        B.at(i)= random;
        i++;
    }
    return B;
};

auto print=[] (function<float(vector<float>)>const & a, vector<float> const & e ){
        cout <<a(e) << "\n";

    };



}
