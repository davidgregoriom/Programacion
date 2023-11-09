#include <iostream>
#include <functional>
#include <array>
using namespace std;

int main(){
  function<float(float, float)> suma = [] (float a, float b){
      
    return a + b;
  };

  function<float(float, float)> resta= [] (float a, float b){
      
    return a - b;
  };

  function<float(float, float)> multiplicar = [] (float a, float b){
      
    return a * b;
  };
    function<float(float, float)> dividir = [] (float a, float b){
      
    return a / b;
  };

  function<void(function<float (float,float)> , float, float)> print = [] (function<float(float,float)> f, float a, float b){
    cout << f(a,b);
      
    
  };


  cout << "Introduce un numero: " << "\n";
  cout << "1 para sumar: " << "\n";
  cout << "2 para restar: " << "\n";
  cout << "3 para multiplicar: " << "\n";
  cout << "4 para dividir: " << "\n";
  int opcion;
  cin >> opcion;

  cout << "Introduce 2 numeros: " << "\n";
  float a; float b; cin >> a >> b;

  array<function<float (float, float)>, 4> op{resta, suma, multiplicar, dividir};
  cout << op.at(opcion)(a,b);
  

  return 0;
  
}