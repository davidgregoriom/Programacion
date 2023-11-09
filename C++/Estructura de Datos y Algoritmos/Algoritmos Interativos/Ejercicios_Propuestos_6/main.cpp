#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void for_each(vector<int> values,function<void (int)> f) {
    for (auto v: values) {
        f(v);
    }
}

int main() {
    // Function to use to print values
    auto print_value = [](int v) { cout << v << endl;};

    // Function to compute the sum
    int sum = 0;
    auto sum_values = [&sum](int v) { sum = sum + v;};

    // ...

    vector<int> values{1, 3, 5, 8, 13};
    for_each(values, print_value);
    for_each(values, sum_values);
    cout << "Total sum: " << sum <<endl;
}
