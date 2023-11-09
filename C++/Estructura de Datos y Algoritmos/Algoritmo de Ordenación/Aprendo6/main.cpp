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

int main() {
  std::vector<int> lhs{2, 8, 11};
  std::vector<int> rhs{1, 3};

  std::cout << "lhs: ";
  print(lhs);
  std::cout << "rhs: ";
  print(rhs);
  auto result = merge(lhs, rhs);
  std::cout << "\nResult: ";
  print(result);
  std::cout << "---\n";
}
