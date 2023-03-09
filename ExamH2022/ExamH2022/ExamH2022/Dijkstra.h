#pragma once
#include <vector>

//
// CANDIDATE NUMBER 422
//


class Node;

class Edge {
public:
	Node* From;
	Node* To;
	int Cost;

	Edge(Node* from, Node* to, int cost);
};

class Node {
public:
	std::vector<Edge*> Connections;

	int TotalCost;
	bool HasBeenVisited;
	bool IsStart;
	bool IsEnd;
	Node* CameFrom;
	int NodeName;

	Node(int name);
	void CreateDualConnections(Node* from, Node* to, int cost);
};

template <typename T>
void Swap(T* xp, T* yp) {
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void RunDijkstra(int NodeToEndAt, Node* NodeArray[], int n);