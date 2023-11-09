#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main(){
  
  function<float (vector<float>)> media = [] (vector<float> v){
    float suma{0};
    for(auto elem: v){
      suma += elem;
    }
    return suma / v.size();
  };


  

  return 0;
  
}