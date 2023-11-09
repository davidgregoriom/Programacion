#include <iostream>
#include <vector>
#include "graph.h"
#include "node.h"
#include "edge.h"

using namespace std;

Graph::Graph() {

}

void Graph::addNode(string name) {
	Node* n = new Node(name);
	nodes.push_back(*n);
}

void Graph::addEdge( int start, int end) {
	adjMatrix[start][end] = 1;
	adjMatrix[end][start] = 1;
}

void Graph::printGraph() {
	cout << "grafo " << endl;
	for (int i = 0; i < node_num; i++) {
		for (int j = 0; j < node_num; j++) {
			cout << matriz[i][j] << " ";
		}
	}
}

void Graph::setEntryPoint(Node node) {

}

void Graph::BFS() {

}

void Graph::DFS_func(int v, bool vis[]) {

}

void Graph::DFS() {

}

void Graph::DFS(Node node) {

}

void Graph::printAdjMatrix() {
	
}