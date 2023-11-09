#include <iostream>
#include <functional>
using namespace std;

int main(){

  //primer float = devuelve un numero decimal
  // tercer y cuarto float = recibe 2 decimales
  //float a y float b son los parametros 
  // return a + b lo que realiza la function
  
  function<float(float, float)> resta= [] (float a, float b){
      
    return a - b;
  };

  cout << resta(1,2);
  return 0;
  
}