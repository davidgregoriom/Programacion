#include <iostream>
#include "edge.h"
#include "graph.h"
#include "node.h"

using namespace std;

int main()
{
	Graph G();
	G.addNode("Opera"); //node 0
	G.addNode("Sol"); //node 1
	G.addNode("Opera"); //node 2
	G.addNode("Arg�elles"); //node 3
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(2, 3);
	G.printGraph();
	G.printAdjMatrix();
	G.BFS();
	G.DFS();
}
