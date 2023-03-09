#pragma once
#include "LinkedList.h"
#include <vector>

//
// CANDIDATE NUMBER 422
//

class HashTable {
public:
	int BUCKETS;

	std::vector<LinkedList*> table;

	HashTable(int buckets);
	void Insert(Task4Node* node);
	void Remove(int IDToRemove);
	Task4Node* Find(int IDToFind);
	void PrintEntireList();
	int HashFunction(Task4Node* key);
};

