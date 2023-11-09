#include <iostream>
#include <vector>

using namespace std;

bool none_of(std::vector<int> values, int value_to_check) {
    for(int i{0};i<values.size();i++){
        if (values.at(i)= value_to_check){
            return true;
        }else{
            return false;
        }

    }
}

int main() {
    std::vector<int> values{1, 3, 5, 8, 13};
    bool all_equal = none_of(values, 4);
    cout << all_equal << "\n";
}
