#include "LinkedList.h"
#include <iostream>

//
// CANDIDATE NUMBER 422
//

Student::Student(int ID, std::string FName, std::string LName, std::string BDay, char Avg) {
	Uniq_ID = ID;
	FirstName = FName;
	LastName = LName;
	Birthday = BDay;
	Average = Avg;
}
Student::Student() {
	Uniq_ID = 0;
	FirstName = "";
	LastName = "";
	Birthday = "";
	Average = 'F';
}

Task4Node::Task4Node() {
	Next = nullptr;
}

LinkedList::LinkedList() {
	Head = nullptr;
	Tail = nullptr;
	Size = 0;
}

void LinkedList::Insert(Student NewStudent) {
	Task4Node* newNode = new Task4Node();
	newNode->Student = NewStudent;

	if (Head == nullptr) {
		Head = newNode;
		Head->Next = nullptr;
	}
	else if (Head != nullptr && Head->Next == nullptr) {
		Tail = newNode;
		Head->Next = Tail;
	}
	else {
		Tail->Next = newNode;
		Tail = newNode;
	}
	Size++;
}

bool LinkedList::Remove(int IDToRemove) {
	Task4Node* p = Head;
	for (int i = 0; i < Size; i++) {
		if (p->Student.Uniq_ID == IDToRemove) {
			if (p == Head) {
				Head = Head->Next;
				delete p;
				Size--;
				return true;
			}
			else if (p == Tail) {
				p = Head;
				while (p->Next != Tail) {
					p = p->Next;
				}
				delete Tail;
				Tail = p;
				Size--;
				return true;
			}
			else {
				p = Head;
				if (p->Next->Student.Uniq_ID == IDToRemove) {
					p->Next = p->Next->Next;
					Size--;
					return true;
				}
				
			}
		}
		else {
			p = p->Next;
		}
	}

	return false;
}

void LinkedList::Print() {
	Task4Node* p = Head;
	for (int i = 0; i < Size; i++) {
		std::cout << "Student ID: " << p->Student.Uniq_ID << std::endl;
		std::cout << "Student's First Name: " << p->Student.FirstName << std::endl;
		std::cout << "Student's Last Name: " << p->Student.LastName << std::endl;
		std::cout << "Student Birthday: " << p->Student.Birthday << std::endl;
		std::cout << "Student Average: " << p->Student.Average << std::endl;
		std::cout << std::endl;
		p = p->Next;
	}
}


