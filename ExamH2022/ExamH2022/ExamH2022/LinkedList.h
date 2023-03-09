#pragma once
#include <string>

//
// CANDIDATE NUMBER 422
//

class Student {
public:
	int Uniq_ID;
	std::string FirstName;
	std::string LastName;
	std::string Birthday;
	char Average;

	Student(int ID, std::string FName, std::string LName, std::string BDay, char Avg);
	Student();
};

class Task4Node {
public:
	Task4Node* Next;
	Student Student;
	Task4Node();
	
};

class LinkedList {
public:
	Task4Node* Head;
	Task4Node* Tail;
	int Size = 0;

	LinkedList();
	void Insert(Student NewStudent);
	bool Remove(int IDToRemove);
	void Print();
};

