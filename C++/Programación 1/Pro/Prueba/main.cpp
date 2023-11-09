
#include <iostream>

int main() {
  std::cout << "Introduce un texto \n";
  std::string textoUsuario = "";
  std::getline (std::cin, textoUsuario);
  char caracterEncontrado = 'a';
  int numeroVecesEncontrado = 0;
  int encontrarPosicion = textoUsuario.find (caracterEncontrado);
  bool encontrado = false;

  for (int num: textoUsuario) {

    if (num == caracterEncontrado) {
      encontrado = true;
      numeroVecesEncontrado = numeroVecesEncontrado + 1;
    }
  }

  std::cout << "La a se observa " << numeroVecesEncontrado << " veces\n";

  if (!encontrado) {
    std::cout << "No se ha encontrado la vocal a";
  }


}
