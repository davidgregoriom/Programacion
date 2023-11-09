#include <iostream>
#include <memory>

using namespace std;
struct persona{
   string nombre;
   int edad{0};
};

int main()
{
    auto p2=make_shared<persona>("pepe",22);
    return 0;
}
