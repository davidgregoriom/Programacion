#include <iostream>

using namespace std;
template<>
void print(Persona const & a){
  std::cout << "nombre: " << a.nombre << "\n";
  std::cout << "edad: " << a.edad << "\n";
}
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
