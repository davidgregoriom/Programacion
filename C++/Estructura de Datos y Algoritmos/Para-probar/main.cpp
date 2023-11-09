#include <iostream>
#include <vector>

bool all_of(std::vector<int> values, int value_to_check) {
    for(auto e: values){
        int i =0;
        if (values.push_back(i)== true){
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
}
