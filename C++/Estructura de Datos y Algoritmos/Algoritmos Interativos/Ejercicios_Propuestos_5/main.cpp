#include <iostream>
#include <vector>

using namespace std;

bool all_of(std::vector<int> values, int value_to_check) {
    int i {0};
    while(i<values.size()){
        if (values.at(i)= value_to_check){
            return true;
            i++;
        }else{
            return false;
        }

    }
}

int main() {
    std::vector<int> values{2, 2, 2, 2, 2, 2};
    bool all_equal = all_of(values, 2);
   cout << all_equal << "\n";
}
