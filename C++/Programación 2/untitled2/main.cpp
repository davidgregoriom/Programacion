#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Flur{
public:
    Flur(int i):i{i}{
         }
    int i;
};
bool operator<(Flur const &a,Flur const &b){
    return 2*a.i <b.i;
}

bool operator+(Flur const &a,Flur const &b){
    return a.i+2*b.i;
}
ostream & operator<<(ostream & os,Flur const &b){
    os<< 2*b.i;
    return os;
}

int main(){
    /*Flur tris{3};
    Flur tras{4};

    if(tris <tras) cout << "Es menor";
    else cout << "Es mayor";
    cout << tris + tras;
    cout << tris;
*/
    vector<int> v{1,2,3,4,5};
    for(uint i{0};i<v.size();i++){
        v.at(i)=i+v.at(i);
    }
    for(auto elem:v){
        cout << elem;
    }

}
