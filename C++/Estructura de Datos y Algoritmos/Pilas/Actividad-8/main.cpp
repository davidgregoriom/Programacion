#include <iostream>

using namespace std;

bool check_braces(const std::string& braces);

int main() {
    check_braces("([](()))[]");  // --> true
    check_braces("([())]");  // --> false
}
