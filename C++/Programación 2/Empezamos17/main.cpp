#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdio.h>

using namespace std;
/*
template<typename T>
void print(T const & a){
  std::cout << a << "\n";
}

int main() {
  print<int>(3); //  3
  print<std::string>("hola"); //  hola
  print<char>('H'); //  hola
  return 0;

}

*/
void foo(std::unique_ptr<int> p){
  std::cout << *p << "\n";
}

void fii(std::unique_ptr<int> & p){
  std::cout << *p << "\n";
}


int main(){
  auto p = std::make_unique<int>(21);

  auto h = p; // error, h y p apunta a lo mismo
  foo(p); // error, el parámetro lo estoy pasando como copia
  fii(p); // CORRECTO, el parametro no se copia, es referencia
  return 0;
}




/*
class Matrix2x2{
  public:
  // public constructor with parameters
  Matrix2x2(std::array<float, 4> const & v);
  // public constructor wihtout parameters
  Matrix2x2();

  void print() const;

  private:
  std::array<float, 4> data;
};

Matrix2x2::Matrix2x2(std::array<float, 4> const & v){
  data = v;
}

Matrix2x2::Matrix2x2(){
  data = {0,0,0,0};
}

void Matrix2x2::print() const{
  std::cout << data.at(0) << "\t" << data.at(1) << "\n";
  std::cout << data.at(2) << "\t" << data.at(3) << "\n";
}

int main(){
  Matrix2x2 myMatrix1{{1,2,3,4}};
  Matrix2x2 myMatrix2;
  myMatrix1.print(); // 1 2
                     // 3 4
  myMatrix2.print(); // 0 0
                     // 0 0
  return 0;
}
*/
