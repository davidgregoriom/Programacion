//Es el 22


#include <iostream>
#include <vector>

int main() {
  std::vector <int> serie {0,1};

  std::cout << "Dime un numero: ";

  int hastaQueNumero = 0;
  std::cin >> hastaQueNumero;


  for (int pos = 2; pos < hastaQueNumero; pos++) {
    serie.push_back(serie.at (pos - 2) + serie.at (pos - 1));

  }

  for (auto elem: serie) {
    std::cout << elem << "\n";
  }
}
