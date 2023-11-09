#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector v1 (0,0,0);
    Vector v2 (0,0,0);
    cin >> v1;
    cin >> v2;
    auto suma=v1+v2;
    auto resta=v1-v2;
    auto multi=v1*v2;
    cout << v1.getModule()<< endl;
    cout << v2.getModule()<< endl;
    cout << suma<< endl;
    cout << resta<< endl;
    cout << multi<< endl;
    cout << (v1==v2);
    return 0;
}
