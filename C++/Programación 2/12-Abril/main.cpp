#include <iostream>
#include "completo.h"
#include "vector3.h"
#include "matriz2.h"
#include <vector>

using namespace std;

template<typename T,typename S>

T media(vector<S> const & v){
    T suma =0;
    for(auto elem: v){
        suma+= elem;
    }
    return suma/v.size();
}



int main()
{
    vector<int> a{1,2,3,4,5,6};
    auto med= media<double,int>(a);
    cout<< med<< "\n";
    return 0;
}
