#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(){
    srand(time(0));
    vector<int>V;
    for(int i{0};i<150;i++){
        V.push_back(rand()%11 + 5);
    }
    auto filter = [](vector<int>const & v,function<bool(int)>g){
        vector<int>result;
        for(auto elem: v){
            if(g(elem))result.push_back(elem);
        }
        return result;
    };
    auto transform = [](vector<int>const & v,function<int(int)>g){
        vector<int>result;
        for(auto elem:v){
            result.push_back(g(elem));
        }
        return result;
    };
    //apartado A:
    auto mayorque12 = [](int h){
        return h >12;
    };
    auto v1 = filter(V,mayorque12);
    //apartado B:
    auto multiplo5 = [](int i){
        return i%5==0;
    };
    auto v2 = filter(V,multiplo5);
    //apartado C:
    auto dobledeV = [](int i){
        return i*5;
    };
    auto v3 = transform(V,dobledeV);
    //apartado D:
    for(auto elem: v1){
          cout << elem << " - ";
        }
        cout<< "\n";

}
