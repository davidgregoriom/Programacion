#include <iostream>
#include <memory>

using namespace std;

class flip{
public:
   int a{3};
   flip(int in):a{in}{cout << a;}
   ~flip(){cout <<"flip";}
};


void fun( shared_ptr<flip>& in){
   in=make_shared<flip>(8);
}

int main()
{
    auto a = make_shared<flip>(4);
    cout<<a->a;
    //fun(a);
    //cout<< a->a;
    return 0;
}



