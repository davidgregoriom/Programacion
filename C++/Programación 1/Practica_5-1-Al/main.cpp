#include <iostream>
#include <vector>
#include <functional>

using namespace std;
 vector<int>filter(vector<int>v,function<bool(int)>f){
     vector<int>result;
     for(auto elem:v){
         if(f(elem))result.push_back(elem);

     }
     return result;
 }

int main(){
    srand(time(0));
    vector<int>miVector;

    for(int i{0};i<50;i++){
        miVector.push_back(rand()%101);
    }
    //apartado a
    function<bool(int)>filtroA = [](int a){
        return (a % 2 ==0);
    };
    //apartado b
    function<bool(int)>filtroB = [](int a){
        return (a % 6 ==0);
    };
    vector<int>resultadoa = filter(miVector,filtroA);
    vector<int>resultadob = filter(miVector,filtroB);

}
