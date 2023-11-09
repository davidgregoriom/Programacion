
#include <iostream>
#include <vector>

float accumulate( float sum, std::vector< float > values) {
    if(values.size()==1){
        sum= values.at(0);
        return sum;
    }else{
        sum= values.at(0)+values.at(1);
        values.at(0)= sum;
        values.at(1)= values.at(values.size()-1);
        values.pop_back();
        return accumulate(sum,values);
    }
}


int main() {
    std::vector< float > values{ 2 , 3 , 5 , 8 };
    std::cout << accumulate( 0 , values) << std::endl;
}
