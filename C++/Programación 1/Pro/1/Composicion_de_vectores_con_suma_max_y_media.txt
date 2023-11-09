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

  function<float (vector<float>)> max = [] (vector<float> v){
      float max{-9999999};
      for(auto elem: v){
        if(max < elem) max = elem;
      }

    return max;
  };

  function<float(vector<float>)> suma = [] (vector<float> v){
    float suma{0};
    for(auto elem: v){
      suma +=elem;
    }
    return suma;
  };

  function<float(function<float(vector<float>)>, function<float(vector<float>)>, vector<vector<float>>)> comp = [] (function<float(vector<float>)> f1, function<float(vector<float>)> f2, vector<vector<float>> vv){

    vector<float> g;
    for(auto v: vv){
      g.push_back(f2(v));
    }
    return f1(g);
  };
  cout << comp(max, max, {{3,4}, {5,1},{7,5}}) << "\n";
  cout << comp(suma, media, {{3,4}, {5,1},{7,5}}) << "\n";

  

  return 0;
  
}