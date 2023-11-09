#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(std::vector<int>& elements) {
  for (int i=0; i<elements.size()-1; i++) {  // 'n-1' iterations
    std::cout << "Iteration " << i << std::endl;
    for (int k=0; k<elements.size()-1; k++) {  // 'n-1' iterations
      // Compare and swap if wrong order
      std::cout << elements[k] << " > " << elements[k+1] << " ? " << (elements[k] > elements[k+1] ? "true": "false") << std::endl;
      if (elements[k] > elements[k+1]) { // compare adyacent values
        std::swap(elements[k], elements[k+1]);
      }
    }
  }
}

int main() {
  std::vector<int> elements{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "Initial vector!" << std::endl;
  for (auto e: elements){
    std::cout << e << ", ";
  }
  std::cout << "\n---\n";
  bubble_sort(elements);
  std::cout << "\nFinal order:\n";
  for (auto e: elements) {
    std::cout << e << ", ";
  }
  std::cout << "\n---\n";
}
