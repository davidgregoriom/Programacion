#include <iostream>
#include <float.h>
#include <vector>
using namespace std;

void bubble_sort(std::vector<float>& elements){
    for (int i=0; i<elements.size()-1; i++) {
      bool any_swap = false;
      std::cout << "Iteration " << i << std::endl;
      for (int k=0; k<elements.size()-1-i; k++) {
        std::cout << elements[k] << " > " << elements[k+1] << " ? " << (elements[k] > elements[k+1] ? "true": "false") << std::endl;
        if (elements[k] > elements[k+1]) {
          std::swap(elements[k], elements[k+1]);
          any_swap = true;
        }
      }
      if (!any_swap) { break;} // return early
    }
}

void selection_sort(std::vector<float>& elements){
    for (int i=0; i<elements.size(); i++) {  // 'n' iterations
      std::cout << "Iteration " << i << std::endl;
      // Search for the minimum element in the right (unordered) section
      int indexMin = i;
      for (int k=i+1; k<elements.size(); k++) {  // 'n-i' iterations
        std::cout << elements[k] << " < " << elements[indexMin] << " ? " << (elements[k] < elements[indexMin] ? "true": "false") << std::endl;
        if (elements[k] < elements[indexMin]) { // keep index of min element
          indexMin = k;
        }
      }
      // Swap current element with the min
      std::swap(elements[i], elements[indexMin]);
    }
}

std::vector<float> merge_sort(const std::vector<float>& elements){

}
void print(const std::vector<int>& elements) {
    for (auto e: elements) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}
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



void quick_sort(std::vector<float>& elements, int left_index, int right_index){


}
int main(){
    std::vector<float> elements{9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "Initial vector!" << std::endl;
    //

    for (auto e: elements) {
      std::cout << e << ", ";
    }
    std::cout << "\n---\n";
    bubble_sort(elements);
    std::cout << "\nFinal order:\n";
    for (auto e: elements) {
      std::cout << e << ", ";
    }
    std::cout << "\n---\n";


    //
    for (auto e: elements) {
      std::cout << e << ", ";
    }
    std::cout << "\n---\n";
    selection_sort(elements);
    std::cout << "\nFinal order:\n";
    for (auto e: elements) {
      std::cout << e << ", ";
    }
    std::cout << "\n---\n";

    //
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



    //


}
