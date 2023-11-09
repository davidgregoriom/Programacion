#include <iostream>
#include "dijkstra.h"

using namespace std;

int main(){ 
    int numVertivces = 7;
    grafo g(numVertivces);

    g.addEdgge(0, 1, 2);
    g.addEdgge(0, 5, 5);
    g.addEdgge(0, 4, 4);
    g.addEdgge(1, 2, 7);
    g.addEdgge(1, 5, 2);
    g.addEdgge(2, 5, 4);
    g.addEdgge(2, 3, 1);
    g.addEdgge(2, 6, 5);
    g.addEdgge(3, 5, 3);
    g.addEdgge(3, 4, 4);
    g.addEdgge(3, 6, 7);
    g.addEdgge(4, 5, 1);

    g.distCorta(0);

    return 0;
}