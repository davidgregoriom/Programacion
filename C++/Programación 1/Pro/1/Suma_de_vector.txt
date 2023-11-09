#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main(){

  //primer float = devuelve un numero decimal
  // tercer y cuarto float = recibe 2 decimales
  //float a y float b son los parametros 
  // return a + b lo que realiza la function
  
  function<float(vector<float>)> suma = [] (vector<float> v){
    float suma{0};
    for(auto elem: v){
      suma +=elem;
    }
    return suma;
  };

  cout << suma(1,2);
  return 0;
  
}