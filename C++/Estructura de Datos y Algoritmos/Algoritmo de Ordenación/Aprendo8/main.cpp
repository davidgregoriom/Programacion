#include <iostream>
#include <vector>
void print(const std::vector<int>& elements) {
    for (auto e: elements) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

// A function to compute the partition
int partition(std::vector<int>& elements, int left_index, int right_index)
{
    auto pivot = elements[left_index];  // any element works
    int i = left_index, j = right_index;

    while(true) {
        while( elements[i] <= pivot && i <= j ) ++i;
        while( elements[j] > pivot ) --j;
        if( i >= j ) break;
        std::swap(elements[i], elements[j]);
    }
    std::swap(elements[left_index], elements[j]);
    return j;
}


int main() {
  std::vector<int> elements{2, 8, 11, 1, 3};

  std::cout << "elements: ";
  print(elements);
  auto pivot_index = partition(elements, 0, elements.size()-1);
  std::cout << "Pivot index: " << pivot_index << std::endl;
  std::cout << "paritition: ";
  print(elements);
}
