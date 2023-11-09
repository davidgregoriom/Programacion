#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

struct Person{
    string name;
    int age;
    string phone;
};

shared_ptr<vector<shared_ptr<Person>>>filter(vector<shared_ptr<Person>> const & p , function<bool(Person)> const & d){
shared_ptr<vector<shared_ptr<Person>>>p_result= make_shared<vector<shared_ptr<Person>>>();;

for(auto p_elem: p){
    if(d(*p_elem))p_result -> push_back(p_elem);

}
    return p_result;
}




int main(){
    vector<shared_ptr<Person>> vv;


    auto p1 = make_shared<Person>(Person{"Maria",28,"11111"});
    auto p2= make_shared<Person>(Person{"Luis",38,"11111"});
    auto p3 = make_shared<Person>(Person{"Lucia",18,"11111"});
    auto p4= make_shared<Person>(Person{"Josema",58,"11111"});

    vv.push_back(p1);vv.push_back(p2);vv.push_back(p3);vv.push_back(p4);

    auto yy =filter(vv,[](Person p){return p.age >18;});


    for(auto p: *yy){
        cout<< p->name << "\n";
    }
    p1-> phone = "3333333333";

    for(auto p: *yy){
        cout << p->phone << "\n";
    }
}
