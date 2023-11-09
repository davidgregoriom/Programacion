#include <iostream>
#include <vector>

using namespace std;

vector<int> factores(int num){
    vector<int> resultado;
    for(int i{1}; i<= num/2; i++){
    if(num % i==0)resultado.push_back(i);
    }
    resultado.push_back(num);
    return resultado;


}



int main()
{
    cout<< "Introduce un numero:\n";
    int i;
    cin >> i;
    cout <<"El factorioal de " << i <<"es "<<"\n";
    return 0;


}
