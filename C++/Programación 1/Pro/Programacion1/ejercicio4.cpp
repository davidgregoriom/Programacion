#include <iostream>
#include <string>

int main() {
  std::cout << "Introduce un texto: ";
  std::string textoUsuario = "";
  std:getline (std::cin, textoUsuario);
  std::string palabra = "password";
  int encontrarPalabra = textoUsuario.find (palabra);

  if (encontrarPalabra == -1) {
    std::cout << "No esta la palabra password";
  }
  else {
    int medirPalabra = palabra.size();
    int posicionInicial = textoUsuario.find(" ", encontrarPalabra + medirPalabra);
    int posicionFinal = textoUsuario.find (" ", medirPalabra + posicionInicial + 1);
    std::string palabraNueva = textoUsuario.substr (posicionInicial, posicionFinal - posicionInicial);
    std::cout << palabraNueva;
  }

}
