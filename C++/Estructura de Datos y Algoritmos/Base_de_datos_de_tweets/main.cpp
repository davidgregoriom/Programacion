#include <iostream>
#include <fstream>
#include <string>
#include "filter.h"
#include "hashtags.h"
#include "elementoslistadoble.h"
#include "lista.h"


using namespace std;

void lectura(){
    std::ifstream infile("");
    std::string line;
    while (std::getline(infile, line)) {
        int separador = line.find(" ");
        string id = line.substr(0, separador);

       std::cout << line << std::endl;
    }
}

int main () {








}

