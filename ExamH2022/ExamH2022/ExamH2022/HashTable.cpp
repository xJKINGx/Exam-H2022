#include "HashTable.h"
#include <iostream>

//
// CANDIDATE NUMBER 422
//

HashTable::HashTable(int buckets) {
	BUCKETS = buckets;
	table = std::vector<LinkedList*>(BUCKETS);

	for (int i = 0; i < buckets; i++) {
		LinkedList* temp = new LinkedList();
		table[i] = temp;
	}
}

void HashTable::Insert(Task4Node* node) {
	int key = HashFunction(node);
	table[key]->Insert(node->Student);
}

void HashTable::Remove(int IDToRemove) {
	for (int i = 0; i < table.size(); i++) {
		if (table[i]->Remove(IDToRemove)) {
			std::cout << "Student deleted from records" << std::endl;
			return;
		}
	}
	std::cout << "Could not find student ID in records" << std::endl;
}

Task4Node* HashTable::Find(int IDToFind)
{
	for (int i = 0; i < table.size() - 1; i++) {
		for (int j = 0; j < table[i]->Size; j++) {
			if (table[i]->Head != nullptr) {
				Task4Node* p = table[i]->Head;
				if (p->Student.Uniq_ID == IDToFind) {
					std::cout << "Student ID: " << p->Student.Uniq_ID << std::endl;
					std::cout << "Student's First Name: " << p->Student.FirstName << std::endl;
					std::cout << "Student's Last Name: " << p->Student.LastName << std::endl;
					std::cout << "Student Birthday: " << p->Student.Birthday << std::endl;
					std::cout << "Student Average: " << p->Student.Average << std::endl;
					std::cout << std::endl;
					return p;
				}
				p = p->Next;
			}
			
		}
	}

	std::cout << "Could not find student in records." << std::endl;
	return nullptr;
}

void HashTable::PrintEntireList() {

	for (int i = 0; i < table.size() - 1; i++) {
		table[i]->Print();
	}
}

int HashTable::HashFunction(Task4Node* key) {
	int intptr = reinterpret_cast<std::uintptr_t>(key);
	return (abs(intptr % BUCKETS));
}
