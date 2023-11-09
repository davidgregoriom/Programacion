#include <iostream>
#include <vector>
void print(const std::vector<int>& elements) {
    for (auto e: elements) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

// A function to merge two ordered lists
int partition(std::vector<int>& elements, int left_index, int right_index)
{
    auto pivot = elements[left_index];
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

// Quick-sort algorithm
void quick_sort(std::vector<int>& elements, int left_index, int right_index) {
    std::cout << "quick_sort: ";
    print(elements);
    // Check for base/trivial case
    if (left_index >= right_index) {
        return;
    }
    else {
        // Compute the pivot
        int pivot_index = partition(elements, left_index, right_index);

        // Apply quick-sort to both sides (pivot is already in place)
        quick_sort(elements, left_index, pivot_index-1);
        quick_sort(elements, pivot_index+1, right_index);
    }
}

int main() {
  std::vector<int> elements{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "Initial vector!" << std::endl;
  print(elements);
  std::cout << "---\n";
  quick_sort(elements, 0, elements.size()-1);
  std::cout << "\nFinal order:\n";
  print(elements);
  std::cout << "---\n";
}
