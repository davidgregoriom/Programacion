#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>


int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1,2};
    std::vector<int> results = {1};

    float i = 2;

    while (nums.size() < 30){

        int n = pow(-1.0, i+1)*nums.at(i-1)-nums.at(i-2);

        if(n%2 != 0 && results.size() < 15){
            results.push_back(n);
        }

        nums.push_back(n);
        i++;
    }

    int sumatorio = 0;

    for(auto num : results){

        std::cout << num << " - ";
        sumatorio += num;
    }

    std::cout << std::endl;
    std::cout << "Media: " << sumatorio/results.size() << std::endl;

    std::sort(nums.begin(), nums.end());

    for(auto num : nums){

        std::cout << num << " - ";
    }

    return 0;
}
