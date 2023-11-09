#include <iostream>
#include <string>
#include <set>
using namespace std;




int main()
{

    int num;
    int divisor=2;
    set<int> factores_primos;

    cout << "introducelo:";
    cin>> num;
    while(num>=divisor){
        while(num % divisor==0){      
            num= num/divisor;
           factores_primos.insert(divisor);
        }
        divisor++;

    }


    cout << " Los factores de un número entero son: ";
    for(auto elem: factores_primos){
        cout << elem << " ";
    }

    return 0;
}
