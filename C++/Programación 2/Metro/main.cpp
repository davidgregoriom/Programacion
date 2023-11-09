#include <iostream>
#include <vector>
#include <fstream>
#include"elementolistadoble.h"
#include "grafo_de_las_estaciones.h"
#include "queue.h"
#include "tipodato.h"
#include "grah.h"

using namespace std;

int main()
{
    string metros{"/home/david/Desktop/Programación 2/Trabajo-Red-de-Metro-de-Madrid"};
    string distances{"/home/david/Desktop/Programación 2/Trabajo-Red-de-Metro-de-Madrid"};
    Grafo_de_las_estaciones<50> metro;



    std::string line;
    std::ifstream citiesFile{metros};
    if (!citiesFile.is_open()) {
        return -1;
    }
    while (std::getline(citiesFile, line)) {
        int found = line.find(' ');
        int node = std::stoi(line.substr(0, found));
        std::string city = line.substr(found+1);
        metro.add_node(node, city);

    }
    std::ifstream distancesFile{distances};
    if (!distancesFile.is_open()) {
        return -1;
    }
    while (std::getline(distancesFile, line)) {
        int found1 = line.find(' ');
        int found2 = line.find(' ', found1 + 1);
        int origin = std::stoi(line.substr(0, found1));
        int target = std::stoi(line.substr(found1 + 1, found2));
        int distance = std::stoi(line.substr(found2 + 1));
        metro.add_edge(origin, target, distance);
    }


    std::cout << metro;


    /*std::string line;
        std::ifstream citiesFile{cities};
        if (!citiesFile.is_open()) {
            return -1;
        }
        while (std::getline(citiesFile, line)) {
            int found = line.find(' ');
            int node = std::stoi(line.substr(0, found));
            std::string city = line.substr(found+1);
            graph.add_node(node, city);
        }

        // - read distances
        std::ifstream distancesFile{distances};
        if (!distancesFile.is_open()) {
            return -1;
        }
        while (std::getline(distancesFile, line)) {
            int found1 = line.find(' ');
            int found2 = line.find(' ', found1 + 1);
            int origin = std::stoi(line.substr(0, found1));
            int target = std::stoi(line.substr(found1 + 1, found2));
            int distance = std::stoi(line.substr(found2 + 1));
            graph.add_edge(origin, target, distance);
        }

        // Override operator<< for your class
        std::cout << graph;
*/
}
