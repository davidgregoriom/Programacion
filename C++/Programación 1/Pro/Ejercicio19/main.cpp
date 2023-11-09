#include <iostream>

using namespace std;

int main(){
        cout << "<Introduce un numero positivo\n";
        int num{0};
        cin >>num;
        int divisor{2};
    while(divisor<num){
            if(num % divisor== 0){
                cout << "No es primo\n";
                return 0;
            }
        divisor++;
    }
    cout << "ES primo!\n";
    return 0;

}
