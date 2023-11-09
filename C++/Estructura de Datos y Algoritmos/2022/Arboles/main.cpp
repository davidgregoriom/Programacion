#include <iostream>

using namespace std;

template<class Object>
struct NodoBinario{
    Object element;
    NodoBinario *izquierda;
    NodoBinario *derecha;
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
