#include <iostream>
#include <vector>

using namespace std;

vector<int> factores(int num){
    vector<int> resultado;
    for(int i{1}; i<= num/2; i++){
    if(num % i==0 && esPrimo(i))resultado.push_back(i);
    }
    resultado.push_back(num);
    return resultado;


}

void printVector(vector<int> v){
    for(auto elem:v){
        cout << elem <<"-";
    }
}


int main()
{
    cout<< "Introduce un numero:\n";
    int i;
    cin >> i;
    cout <<"El factorioal de " << i <<"es "<<"\n";
    return 0;


}
