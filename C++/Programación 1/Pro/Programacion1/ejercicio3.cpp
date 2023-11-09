#include <iostream>

int main() {
 std::string fraseEjercicio = "Tres tristes tigres comen trigo en un trigal";

 int encontrar = fraseEjercicio.find("tri");
 std::cout << "El primer tri esta en la posicion " << encontrar << "\n";

 encontrar = fraseEjercicio.find("tri", encontrar + 5);
 std::cout << "El segundo tri esta en la posicion " << encontrar << "\n";

 encontrar = fraseEjercicio.find("tri", encontrar + 1);
 std::cout << "El tercero tri esta en la posicion " << encontrar;
}
