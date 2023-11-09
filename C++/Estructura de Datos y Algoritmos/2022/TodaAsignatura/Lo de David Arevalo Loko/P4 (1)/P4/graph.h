#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"
#include <string>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Graph{
	private:
		int node_num; /**< Node counter */
		Node* entryPoint; /**< Entry point to the graph, normally node 0 */
		vector<Node> nodes; /**< Node list, used as Adjacency List along the nodes neighbour list */
		vector<vector<int>>adjMatrix; /**< Adjacency Matrix */
		void updateAdjMatrix();
	public:
		Graph();
		void addNode(string name);
		void addEdge( int start, int end);
		void printGraph();
		void setEntryPoint(Node node);
		void BFS();
		void DFS_func(int v, bool vis[]);
		void DFS();
		void DFS(Node node);
		void printAdjMatrix();
		int matriz[100][100];
};

#endif // GRAPH_H
