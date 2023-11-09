#include <iostream>
#include <vector>

using namespace std;

bool all_of(std::vector<int> values, int value_to_check) {
    for(int i{0};i<values.size();i++){
        if (values.at(i)= value_to_check){
            return true;
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
