#include <iostream>
#include <vector>

// It is always useful to have a function to print a vector at hand
void print_vector(std::vector<int> values) {
    for (auto v: values) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
}
// This function takes a portion/slice of the given vector
std::vector<int> slice(std::vector<int> values, int begin, int end) {
    if (begin >= end) { return std::vector<int>{}; }
    return std::vector<int>(values.begin() + begin, values.begin() + end);
}

bool binary_search(std::vector<int> values, int value_to_find) {
    print_vector(values); // Visual debugging: see the vector arriving to the function in each iteration
    if (values.empty()) { return false; } // If the vector is empty, the value is not there
    int middle = values.size() / 2;
    // TODO: Implement algorithm here
    if (value_to_find < values.at(middle)) {
        auto new_vector = slice(values, 0, middle);
        return binary_search(new_vector, value_to_find);
    }
    else if (value_to_find > values.at(middle)) {
        auto new_vector = slice(values, middle+1, values.size());
        return binary_search(new_vector, value_to_find);
    }
    else {
        return true;
    }
}

int main() {
    std::vector<int> values{1, 3, 5, 8, 13};
    int found = binary_search(values, 8);
    if (found) {
        std::cout << "Element found" << std::endl;
    }
    else {
        std::cout << "Element not found" << std::endl;
    }
}
