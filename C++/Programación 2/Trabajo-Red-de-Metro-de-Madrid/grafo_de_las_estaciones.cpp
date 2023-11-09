#include "grafo_de_las_estaciones.h"

Graph::Graph()
{
    // Nodes
    for (int i=0; i<N; i++) {
        nodes[i] = nullptr;
    }

    // Edges
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            edges[i][j] = nullptr;
        }
    }
}
