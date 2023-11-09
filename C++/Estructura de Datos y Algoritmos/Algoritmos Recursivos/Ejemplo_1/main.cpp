#include <iostream>

int sum_n_times(int a, int n) {
    // TODO: Stop condition: base/trivial case
    if (n == 1) { return a; }
    return a+sum_n_times(a, n-1);
}


int prod_n_times(int a, int n) {
    // Recursive algoritm to multiple 'n' times a number 'a'
    if (n == 1) { return a; }
    return a*prod_n_times(a, n-1);
}


int factorial(int s) {
    // Compute factorial of 'n' as 'n * (n-1)!'
    if (s == 0) { return 1; } // Stop condition: base/trivial case
    return s*factorial(s-1);
}


int main() {
    int a = 2;
    int n = 3;
    int result = sum_n_times(2, 3);
    std::cout << "a*n = " << result << std::endl;


    int result2 = prod_n_times(2, 3);
    std::cout << "a^n = " << result2 << std::endl;


    int s = 4;
    int result3 = factorial(4);
    std::cout << "n! = " << result3 << std::endl;
}
