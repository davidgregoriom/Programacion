#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

class grafo {
	int numVertices; 
	list<pair<int, int>> * adj;

	public:
		grafo(int numVertices);
		void addEdgge(int start, int end, int peso);
		void distCorta(int s);
};

grafo::grafo(int numVertices) { 
	this->numVertices = numVertices;
	adj = new list<pair<int, int>>[numVertices];
}

void grafo::addEdgge(int start, int end, int peso) { 
	adj[start].push_back(make_pair(end, peso));
	adj[end].push_back(make_pair(start, peso));
}

void grafo::distCorta(int s) { //distancia mas corta desde s a todos los vertices

	set<pair<int, int>>  vertices; //set para almacenar los verties
	vector<int> dist(numVertices, 100); //vector para las distancias que va desde v hasta 100

	vertices.insert(make_pair(0, s)); 
	dist[s] = 0; //la distancia se inicializa en 0

	while (!vertices.empty()) {
		pair<int, int> tmp = *(vertices.begin()); //El primer vertice de set es el de menor distancia
		vertices.erase(vertices.begin());

		int u = tmp.second;

		list<pair<int, int>>::iterator i;

		for (i = adj[u].begin(); i != adj[u].end(); i++) {
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight) {
				if (dist[v] > dist[u] + weight) {
					if (dist[v] != 100){
						vertices.erase(vertices.find(make_pair(dist[v], v)));
					}
					dist[v] = dist[u] + weight;
					vertices.insert(make_pair(dist[v], v));
				}
			}
		}
	}
	cout << "Vertices    Distancia\n";
	for (int i = 0; i < numVertices; i++) {
		printf("%d \t\t %d\n", i, dist[i]);
	}
}

