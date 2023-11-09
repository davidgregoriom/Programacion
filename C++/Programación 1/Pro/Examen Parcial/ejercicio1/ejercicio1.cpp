#include <iostream>
#include <array>
#include <set>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main(){
    srand(time(NULL));
    array<int,100> nums {};
    set<double> mym{};
    set<int> pares{};

    for(int i=0;i<100;i++){
        nums.at(i)=rand() % 550+5;
    }

    for(int elem:nums) mym.insert(elem);

    int contador{0};
    for(auto elem:mym){
        if(contador==0){
            cout << "El valor minimo es: "<< elem << "\n";
        }else if(contador==mym.size()-1){
            cout << "El valor maximo es: "<< elem << "\n";
        }
        contador++;
    }
   for(auto elem:nums){
       if(elem%2==0){
           pares.insert(elem);
       }
   }

}

