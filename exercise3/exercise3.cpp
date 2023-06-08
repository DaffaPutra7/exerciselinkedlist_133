#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
	Node* prev;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList();
	void addNode();
	bool search(int rollNo, Node** Pratama, Node** Daffa);
	bool listEmpty();
	bool delNode(int rollNo);
	void traverse();
};

CircularLinkedList::CircularLinkedList() {
	LAST = NULL;
}

void CircularLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;
	cout << "\nEnter the name of the student : ";
	cin >> nm;
	Node* newNode = new Node();
	newNode->rollNumber = nim;
	newNode->name = nm;

	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST; // step 3
		if (LAST != NULL)
			LAST->prev = newNode;
		newNode->prev = NULL;
		LAST = newNode;
		return;
	}


	Node* Daffa = LAST;
	Node* Pratama = NULL;
	while (Daffa->next != NULL && Daffa->next->rollNumber < nim)
	{
		Pratama = Daffa;
		Daffa = Daffa->next;
	}

	if (Daffa->next != NULL && nim == Daffa->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = Daffa->next;
	newNode->prev = Daffa;
	if (Daffa->next != NULL)
		Daffa->next->prev = newNode;
	Daffa->next = newNode;
}

bool CircularLinkedList::search(int rollNo, Node** Pratama, Node** Daffa) {
	*Pratama = LAST->next;
	*Daffa = LAST->next;

	while (*Daffa != LAST) {
		if (rollNo == (*Daffa)->rollNumber) {
			return true;
		}
		*Pratama = *Daffa;
		*Daffa = (*Daffa)->next;
	}
	if (rollNo == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::delNode(int rollNo) {
	Node* Pratama, * Daffa;
	Pratama = Daffa = NULL;
	if (search(rollNo, &Pratama, &Daffa) == false)
		return false;
	if (Daffa->next != NULL)
		Daffa->next->prev = Pratama; // step 2
	if (Pratama != NULL)
		Pratama->next = Daffa->next; // step 3
	else
		LAST = Daffa->next;

	delete Daffa; // step 4
	return true;
}

bool CircularLinkedList::listEmpty() {
	return (LAST == NULL);
}

void  CircularLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are : " << endl;
		Node* DaffaNode = LAST;
		while (DaffaNode != NULL) {
			cout << DaffaNode->rollNumber << " " << DaffaNode->name << endl;
			DaffaNode = DaffaNode->next;
		}
	}
}


int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5) : ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {

			}
			case '2': {

			}
			case '3':
				obj.traverse();
				break;
			case '4':
				return 0;
			default:
				cout << "Invalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}


