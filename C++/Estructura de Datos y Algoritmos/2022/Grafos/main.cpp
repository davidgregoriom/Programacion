

#include <iostream>
#include "Vertex.h"
#include "Graph.h"

int main()
{
    Graph g;
    Vertex v1{ 1 };
    Vertex v2{ 2 };
    v1.connectVertex(2);
    g.addVertex(v1);
    g.addVertex(v2);
    g.printGraph();
}
