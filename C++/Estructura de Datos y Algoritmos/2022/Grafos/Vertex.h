#pragma once
#include <vector>
#include <iostream>

class Vertex
{
public:
	Vertex(int v, std::vector<int> a) : vertex_number(v), adjacents(a) {}
	Vertex(int v) :vertex_number(v) {};
	void connectVertex(const  int& v);
	void printAdjacentList();
	int getVertexNumber();
private:
	int vertex_number;
	std::vector<int> adjacents;
};

