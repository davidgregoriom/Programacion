#pragma once
#include <vector>
#include "Vertex.h"
class Graph
{
public:
	Graph(std::vector<Vertex> v) : vertexContainer(v) {}
	Graph() {};
	void addVertex(Vertex& v);
	void printGraph();
private:
	std::vector<Vertex> vertexContainer;

};