#include <iostream>

using namespace std;

int suma(int a, int b){
    return a+b;
}
 int resta(int a, int b){
  return a-b;


}

int main(){
    string operacion;
    cout << "Escribe\"restar\"o\"sumar\" segun lo que quieras hacer:";
    cin >> operacion;

    cout << "introduce dos numeros:";
    int x; int y;
    cin>> x >> y;

    if(operacion == "sumar"){
        cout << suma (x,y);

    }else if(operacion == "restar"){
        cout << resta(x,y);
    }else{
        cout <<"No reconozco la operacion" << operacion << "\n";
    }
    return 0;
}
