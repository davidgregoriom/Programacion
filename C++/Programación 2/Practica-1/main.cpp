#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>

#include "censo.h"
using namespace std;

auto busqueda_nombre= [](shared_ptr<string>a , shared_ptr<string>b,shared_ptr<string> c,shared_ptr<string>d){

};
auto filter =[](vector<shared_ptr<Censo>> const &v, function<bool(int)>g){
    vector<shared_ptr<Censo>> result;
    for(auto elem:v){
        if(g(elem))result.push_back(elem);
    }
    return result;
};

int main(){
    vector<shared_ptr<Censo>>c1;
    vector<shared_ptr<Censo>>c2;
    vector<shared_ptr<Censo>>c3;
    vector<shared_ptr<Censo>>c4;
    vector<shared_ptr<Censo>>c5;


    vector<shared_ptr<Censo>>CC;
    Censo elcenso();

    for(int i=0 ; i<5 ; i++){
        cout << "Introduzca sus datos";
        shared_ptr<string>pname=make_shared<string>();
        shared_ptr<string>pDNI=make_shared<string>();
        shared_ptr<string>pphone=make_shared<string>();
        shared_ptr<int>pyear=make_shared<int>();
        shared_ptr<int>page= make_shared<int>();
        shared_ptr<int>pisAdult = make_shared<int>();

        cin >> *pname ;
        cin >> *pDNI ;
        cin >> *pphone;
        cin >> *pyear ;
        cin >> *page;
        cin >> *pisAdult;


    }




}

