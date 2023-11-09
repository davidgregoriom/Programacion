#include <iostream>
#include <string>
using namespace std;
 
constexpr int factor_temporal = 3;
constexpr int factor_temporal1 = 4;

std::string message_dream(std::string word, int level) {
    
    if (level == 0) { return word; }
    else {
        
        std::string ret;
        for (auto c: word) {
            for (auto i=0; i<factor_temporal; i++) {
                ret.push_back(c);
            }
        }
        
        return message_dream(ret, level - 1);
    }
}

std::string message_dream1(std::string word, int level) {
    
    if (level == 0) { return word; }
    else {
        
        std::string ret;
        for (auto c: word) {
            for (auto i=2; i<factor_temporal1; i++) {
                ret.push_back(c);
            }
        }
        
        return message_dream1(ret, level - 1);
    }
}
 
int main() {
    
    std::cout << "Realidad: " << message_dream1("Hola", 0) << std::endl;
    std::cout << "Realidad: " << message_dream("Soy Ana", 0) << std::endl;
    std::cout << "Nivel 1: " << message_dream("Soy Ana", 1) << std::endl;
    std::cout << "Nivel 2: " << message_dream1("Hola", 2) << std::endl;
}