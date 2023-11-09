#include <iostream>
#include <vector>

using namespace std;

struct Vect3{
    float x,y,z;
};

template<typename T,typename S>

T media(vector<S> const & v){
    T suma =0;
    for(auto elem: v){
        suma+= elem;
    }
    return suma/v.size();
}
template<>
Vect3 media(vector<Vect3>const & v){
    Vect3 result{0,0,0};
    for(auto elem:v){
        result.x += elem.x;
        result.y += elem.y;
        result.z += elem.z;
    }
    result.x /= v.size();
    result.y /= v.size();
    result.z /= v.size();

    return result;
}
ostream & operator<<(ostream &os, Vect3 const & v){
     os << v.x << "," << v.y << "," << v.z;
     return os;
}


int main()
{
    vector<int> a{1,2,3,4,5,6};
    vector<float> b{1,2,3,4,5,6};
    auto med= media<double,int>(a);
    auto med2= media<double,float>(b);
    cout<< med<< "\n";

    Vect3 a{1,2,3};
    Vect3 b{2,3,4};
    Vect3 c{3,4,5};

    vector<Vect3>{a,b,c};

    auto m= media<Vect3,Vect3>(v);

    cout << m;
    return 0;
}
