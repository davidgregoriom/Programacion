#include <iostream>



int main()
{
  std::string fraseMancha = "En un lugar de la Mancha, de cuyo nombre no quiero acordarme ";
  std::string frase1 = fraseMancha.substr (0, 15);
  std::cout << frase1 << "\n";

  std::string frase2 = fraseMancha.substr (24, 40);
  std::cout << frase2 << "\n";
}
