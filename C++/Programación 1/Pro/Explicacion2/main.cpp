#include <iostream>

using namespace std;

int factorial(int num){
    int resultado{1};
    for(int i{2}; i <=num;i++){
        resultado = resultado *i;
    }
    return resultado;
}

bool esPrimo(int num){
    for (int i{2}; i< num/2 ; i++){
        if(num % i ==0){
            return false;
        }
    }
    return true;

}


int main(){

    cout<< "Introduce un numero:\n";
    int i;
    cin >> i;
    int fact =factorial(i);
    cout <<"El factorioal de " << i <<"es " << fact << "\n";
    return 0;
}
