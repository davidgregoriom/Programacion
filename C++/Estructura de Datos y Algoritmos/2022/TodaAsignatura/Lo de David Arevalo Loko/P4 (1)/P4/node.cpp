#include "node.h"
#include "graph.h"

Node::Node(string name) {
	
}

int Node::getID() const {
	return ID;
}

void Node::setID(int id)const {
	id = ID;
}

string Node::getName() const {
	return name;
}
void Node:: setName(string nom) const {
	nom = name;
}

void Node::addNeighbours(Node* node) {
	
}
vector<Node*> Node::getNeighbours() const {

}