#include <iostream>
#include <functional>
#include <vector>
#include <math.h>
using namespace std;

int main(){

  //primer float = devuelve un numero decimal
  // tercer y cuarto float = recibe 2 decimales
  //float a y float b son los parametros 
  // return a + b lo que realiza la function
  
   function<float(vector<float>)> resta = [] (vector<float> v){
    
    float resta{v.at(0)};
    for(int i=1; i<v.size(); i++){
      resta -= v.at(i);
    }
    return resta;
  };


  return 0;
  
}