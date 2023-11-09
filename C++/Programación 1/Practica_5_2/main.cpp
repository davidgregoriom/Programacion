#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;
int funcion(string operacion, int j){
    for(int k=0; k == operacion.size();k++){
        if(operacion.at(k)='+'){
        j = j + operacion.at(k+1);
        }else if(operacion.at(k)='-'){
        j = j - operacion.at(k+1);
        }

    }
    return j;
}


int main(){
    string operacion;
    cout<<"Introduce la operacion matematica:\n";
    cout<<"PD:Tiene que ser todo junto,sin espacios y numeros del 0 al 9 ejem:(1+2+3+1)\n";
    getline(cin,operacion);
    cout << operacion<< "\n";
    int j = operacion.at (0);
    funcion(operacion,j);
    cout<<"La operacion es:"<<j<< "\n";


}
