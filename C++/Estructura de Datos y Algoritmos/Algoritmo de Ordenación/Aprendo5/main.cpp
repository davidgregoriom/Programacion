#include <iostream>
#include <vector>
void print(const std::vector<int>& elements) {
    for (auto e: elements) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

// A function to merge two ordered lists
std::vector<int> merge(const std::vector<int>& lhs,
                       const std::vector<int>& rhs)
{
    std::vector<int> ret;
    auto left_iterator = 0;
    auto right_iterator = 0;

    // Iterate the two vectors at the same time, adding the lowest element
    while (left_iterator != lhs.size() && right_iterator != rhs.size()) {
        if (lhs[left_iterator] < rhs[right_iterator]) {
            ret.push_back(lhs[left_iterator]);
            left_iterator++;
        }
        else {
            ret.push_back(rhs[right_iterator]);
            right_iterator++;
        }
    }

    // Add remaining elements
    for (int i=left_iterator; i<lhs.size(); i++) {
        ret.push_back(lhs[i]);
    }
    for (int i=right_iterator; i<rhs.size(); i++) {
        ret.push_back(rhs[i]);
    }
    return ret;
}

// Merge-sort algorithm
std::vector<int> merge_sort(const std::vector<int>& elements) {
    std::cout << "merge_sort: ";
    print(elements);
    // Check for base/trivial case
    if (elements.size() <= 1) {
        return elements;
    }
    else {
        // Split the vector in two
        auto middle = elements.size()/2;
        std::vector<int> left{elements.begin(), elements.begin() + middle};
        std::vector<int> right{elements.begin() + middle, elements.end()};

        // Apply merge_sort to each of them
        left = merge_sort(left);
        right = merge_sort(right);

        // Merge those two (already) ordered vectors
        return merge(left, right);
    }
}

int main() {
  std::vector<int> elements{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "Initial vector!" << std::endl;
  print(elements);
  std::cout << "---\n";
  elements = merge_sort(elements);
  std::cout << "\nFinal order:\n";
  print(elements);
  std::cout << "---\n";
}
