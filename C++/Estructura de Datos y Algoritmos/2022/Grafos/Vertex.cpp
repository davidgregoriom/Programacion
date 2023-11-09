#include "Vertex.h"
void Vertex::connectVertex(const  int& v) {
	this->adjacents.push_back(v);
}
void Vertex::printAdjacentList() {
	for (auto element : adjacents) {
		std::cout << "\t" << element << std::endl;;
	}
}

int Vertex::getVertexNumber()
{
	return vertex_number;
}


