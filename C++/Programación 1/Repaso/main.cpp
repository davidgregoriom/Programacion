#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

std::function<int (int, int)> suma = [] (int a, int b) {
  return a + b;
};

std::function<int (int, int) > resta = [] (int a, int b) {
  return a - b;
};

int operacion(int a, int b, std::function<int (int, int)> const & op){
  return op(a,b);
}


int main(){
    std::cout << "Introduce s para sumar 2 y 3 o r para restar 2 y 3: ";
      char c; std::cin >> c;

      if(c == 's') std::cout << operacion(2,3, suma);
      if(c == 'r') std::cout << operacion(2,3, resta);

}

