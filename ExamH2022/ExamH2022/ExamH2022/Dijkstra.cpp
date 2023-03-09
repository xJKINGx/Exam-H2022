#include "Dijkstra.h"
#include <iostream>

//
// CANDIDATE NUMBER 422
//

Edge::Edge(Node* from, Node* to, int cost) {
	From = from;
	To = to;
	Cost = cost;
}

Node::Node(int name) {
	TotalCost = -1;
	HasBeenVisited = false;
	CameFrom = nullptr;
	IsStart = false;
	IsEnd = false;
	NodeName = name;
}

void Node::CreateDualConnections(Node* from, Node* to, int cost) {
	from->Connections.push_back(new Edge(from, to, cost));
	to->Connections.push_back(new Edge(to, from, cost));
}

void RunDijkstra(int NodeToEndAt, Node* NodeArray[], int n) {
	std::vector<Node*> PriorityQueue{};
	
	bool HasFoundEnd = false;

	for (int i = 0; i < n; i++) {
		NodeArray[i]->HasBeenVisited = false;
		NodeArray[i]->TotalCost = -1;
	}

	for (int i = 0; i < n; i++) {
		PriorityQueue.push_back(NodeArray[i]);
	}

	PriorityQueue[0]->TotalCost = 0;
	PriorityQueue[0]->CameFrom = PriorityQueue[0];

	for (int i = 0; i < PriorityQueue.size(); i++) {
		for (int j = 0; j < PriorityQueue[i]->Connections.size(); j++) {

			Node* CurrentNode = PriorityQueue[i]->Connections[j]->To;
			Edge* CurrentEdge = PriorityQueue[i]->Connections[j];

			if (CurrentNode->TotalCost == -1) {
				CurrentNode->TotalCost = (PriorityQueue[i]->TotalCost + CurrentEdge->Cost);
				CurrentNode->CameFrom = PriorityQueue[i];
			}
			else if ((PriorityQueue[i]->TotalCost + CurrentEdge->Cost) < CurrentNode->TotalCost) {
				if (CurrentNode != NodeArray[0]) {
					CurrentNode->CameFrom = PriorityQueue[i];
					CurrentNode->TotalCost = (PriorityQueue[i]->TotalCost + CurrentEdge->Cost);
				}
			}

		}
	}
	std::cout << "0 to " << NodeToEndAt << " --> " << NodeArray[NodeToEndAt]->TotalCost << std::endl;
}
