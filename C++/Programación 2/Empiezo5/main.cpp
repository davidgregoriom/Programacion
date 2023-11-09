#include <iostream>
#include <ostream>
#include <istream>
using namespace std;

class Complex {
  friend Complex operator+ (Complex const & c1, Complex const & c2);

  friend Complex operator- (Complex const & c1, Complex const & c2);

  friend Complex operator* (Complex const & c1, Complex const & c2);

 friend bool  operator== (Complex const & c1, Complex  const  & c2);

  friend std::ostream & operator << (std::ostream & os, Complex c);
  friend istream & operator >> (istream & is, Complex  & c);


  public:
  Complex(): r{0}, i{0} {};
  Complex (float r, float i) : r{r}, i{i} {}

  private:
  float r, i;
};



Complex operator+ (Complex const & c1, Complex const & c2) {
  Complex result {c1.r + c2.r, c1.i + c2.i};
  return result;
}

Complex operator- (Complex const & c1, Complex const & c2) {
  Complex result {c1.r - c2.r, c1.i - c2.i};
  return result;
}

Complex operator* (Complex const & c1, Complex const & c2) {
  Complex result {c1.r * c2.r -c1.r * c2.r, c1.r * c2.i + c1.i * c2.r};
  return result;
}

 bool  operator== (Complex  const & c1, Complex   const & c2){
    return (c1.r == c2.r && c1.i == c2.i);

}



ostream & operator << (ostream  & os, Complex  c) {  //Mostrar numeros complejos
  os << c.r << "+" << c.i << "*i";
  return os;
}

istream & operator >> (istream & is, Complex  & c){ //Introducir numeros complejos
    is >> c.r;
    is >> c.i;
    return is;
}


int main() {
  Complex a{1,2};
  Complex b{2,2};

  Complex c = a + b;
  Complex d = a - b;

  cout << c << "\n";
  cout << d << "\n";

}
