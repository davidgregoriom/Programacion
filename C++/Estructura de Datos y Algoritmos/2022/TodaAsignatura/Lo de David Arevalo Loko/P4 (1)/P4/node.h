#pragma once
#ifndef NODE_H
#define NODE_H
#include<vector>
#include <string>
#include "graph.h"

using namespace std;

class Node{
	private:
		int ID;
		vector<Node*> neighbours;
		string name;
	public:
		Node(string name);
		int getID() const;
		void setID(int id) const;
		string getName() const;
		void setName(string nom) const;
		void addNeighbours(Node* node);
		vector<Node*> getNeighbours() const;
};

#endif // NODE_H
