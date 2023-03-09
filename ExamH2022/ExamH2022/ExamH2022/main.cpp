#include <iostream>
#include "Dijkstra.h"
#include "HashTable.h"
#include <string>

int main() {

	//
	// CANDIDATE NUMBER 422
	// Task 1 is in the main folder titled "Task1.jpg"
	//

	//
	// TASK 2
	//

	const int GraphSize = 9;
	Node* AllNodes[GraphSize];
	// AllNodes index goes from 0 to 7

	for (int i = 0; i < GraphSize; i++) {
		Node* newNode = new Node(i);
		AllNodes[i] = newNode;
	}

	for (int i = 0; i < GraphSize; i++) {
		Node* newNode = new Node(i);
		std::cout << i << ": " << AllNodes[i]->NodeName << std::endl;
	}

	// Connections for 0
	AllNodes[0]->CreateDualConnections(AllNodes[0], AllNodes[1], 3);
	AllNodes[0]->CreateDualConnections(AllNodes[0], AllNodes[7], 12);
	// Connections for 1
	AllNodes[1]->CreateDualConnections(AllNodes[1], AllNodes[2], 6);
	AllNodes[1]->CreateDualConnections(AllNodes[1], AllNodes[7], 5);
	// Connections for 2
	AllNodes[2]->CreateDualConnections(AllNodes[2], AllNodes[8], 3);
	AllNodes[2]->CreateDualConnections(AllNodes[2], AllNodes[3], 4);
	AllNodes[2]->CreateDualConnections(AllNodes[2], AllNodes[5], 8);
	// Connections for 3
	AllNodes[3]->CreateDualConnections(AllNodes[3], AllNodes[4], 7);
	AllNodes[3]->CreateDualConnections(AllNodes[3], AllNodes[5], 6);
	// Connections for 4
	AllNodes[4]->CreateDualConnections(AllNodes[4], AllNodes[5], 5);
	// Connections for 5
	AllNodes[5]->CreateDualConnections(AllNodes[5], AllNodes[6], 6);
	// Connections for 6
	AllNodes[6]->CreateDualConnections(AllNodes[6], AllNodes[8], 4);
	AllNodes[6]->CreateDualConnections(AllNodes[6], AllNodes[7], 3);
	// Connections for 7
	AllNodes[7]->CreateDualConnections(AllNodes[7], AllNodes[8], 6);
	// Connections for 8 are already added by 2, 6 and 7 

	// For debugging, shows connections and cost between nodes
	//for (int i = 0; i < GraphSize; i++) {
	//	for (int j = 0; j < AllNodes[i]->Connections.size(); j++) {
	//		std::cout << "Node " << AllNodes[i]->NodeName << "'s connected to " << AllNodes[i]->Connections[j]->To->NodeName
	//			<< " with a cost of " << AllNodes[i]->Connections[j]->Cost << std::endl;
	//	}
	//}

	AllNodes[0]->IsStart = true;
	for (int i = 0; i < GraphSize; i++) {
		AllNodes[i]->IsEnd = true;
		RunDijkstra(i, AllNodes, GraphSize);
		AllNodes[i]->IsEnd = false;
	}

	//
	// TASK 3
	//

	HashTable* Hash = new HashTable(10);

	bool Looping = true;
	while (Looping) {
		std::cout << "---- TASK 4 ----" << std::endl;
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1: Insert" << std::endl;
		std::cout << "2: Delete a record" << std::endl;
		std::cout << "3: Find a record" << std::endl;
		std::cout << "4: Print the table" << std::endl;
		std::cout << "5: Quit?" << std::endl;
		std::cout << "Type in number here: " << std::endl;

		std::string input = "";

		getline(std::cin, input);

		int ConvertedInput = stoi(input);
		int ID{};
		std::string fName;
		std::string lName;
		std::string bDay;
		std::string Grade;
		Student newStudent;
		Task4Node* newNode;

		switch (ConvertedInput) {
		case 1:
			// Insert
			std::cout << "Student's ID number: ";
			getline(std::cin, input);
			ID = stoi(input);
			std::cout << "Student's First Name: ";
			getline(std::cin, fName);
			std::cout << "Student's Last Name: ";
			getline(std::cin, lName);
			std::cout << "Student's Birthday: ";
			getline(std::cin, bDay);
			std::cout << "Student's Average Grade: ";
			getline(std::cin, Grade);
			newStudent = Student(ID, fName, lName, bDay, Grade[0]);
			newNode = new Task4Node();
			newNode->Student = newStudent;
			Hash->Insert(newNode);
			break;
		case 2:
			// Delete
			std::cout << "Type ID to Remove: ";
			getline(std::cin, input);
			ID = stoi(input);
			Hash->Remove(ID);
			break;
		case 3:
			// Find
			std::cout << "Type ID to Find: ";
			getline(std::cin, input);
			ID = stoi(input);
			Hash->Find(ID);
			break;
		case 4:
			// Print table
			Hash->PrintEntireList();
			break;
		case 5:
			// Quit
			Looping = false;
			break;
		default:
			Looping = false;
			break;
		}
	}

	

	return 0;
}