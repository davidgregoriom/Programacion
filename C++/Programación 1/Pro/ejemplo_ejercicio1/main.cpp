#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;
int numeros_aleatorios(){
    int numeros;
    int numero1;
    int numero2;
    cout << "¿Cuántos números aleatorios se desean generar? ";
    cin >> numeros;
    cout << " ¿Entre qué valores serán los números aleatorios?";
    cin >> numero1 >> numero2;
    return numeros; return numero1; return numero2;

}
vector<int>numeros(int & numero1,int & numero2,int & numero3){
    vector<int> num;
    for(int i = 0;i==numero1;i++){
       num.at(i) = rand() % numero2+ numero3;

    }
    return num;
}


int main() {
    int num1 = numeros_aleatorios();
    int num2 = numeros_aleatorios();
    int num3 = numeros_aleatorios();
    vector<int> num = numeros(num1,num2,num3);
    return 0;
}
