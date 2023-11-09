#include "Graph.h"
void Graph::addVertex(Vertex& v) {
	vertexContainer.push_back(v);
}

void Graph::printGraph() {
	for (auto element : vertexContainer) {
		std::cout << "Vertex " << element.getVertexNumber() << " Connected to: " << std::endl;
		element.printAdjacentList();
	}
}