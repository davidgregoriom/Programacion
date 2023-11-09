#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int f(vector<int> const & v, function<bool(int,int)>const & foo){
    int result {0};
    for(int i {0};i<v.size();i++){
        if(foo(i,v.at(i))) result += v.at(i);
    }
    return result;
}





int main()
{
    int aux= f({1,2,3,4,5,6}, [](int a, int b)->bool{
       return ((a+b)%2 == 0);
    });
    cout << aux << "\n";
    return 0;
}
