# include <iostream>
# include <sstream>
# include <string>
# include "LinkedList.h"
# include "Node.h"

using std::string, std::ostream;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// TODO: implement this function

}

LinkedList::~LinkedList() {
	// TODO: implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) {
	// TODO: implement this function
	Node* curr = source.head;

	while(curr) {
		insert(curr->data.id, curr->data.year, curr->data.month, curr->data.temperature);
		curr = curr->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
	if (this != &source) {
		clear();
		Node* curr = source.head;
		while(curr) {
			insert(curr->data.id, curr->data.year, curr->data.month, curr->data.temperature);
			curr = curr->next;
		}
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
	Node* node = new Node(location, year, month, temperature);
	if (!head) { // if linked list is empty
		head = node;
		tail = node;
	}
	else {
		if (node->data < head->data) { // head
			node->next = head;
			head = node;
		}
		else {
			Node* curr = head;

			while(curr->next) {
				if (node->data < curr->next->data) {
					break;
				}
				curr = curr->next;
			}

			if (curr->next) { // everything except tail
				node->next = curr->next;
				curr->next = node;
			}
			else { // tail
				curr->next = node;
				tail = node;
			}
		}
	}
}

void LinkedList::clear() {
	// TODO: implement this function
	Node* curr = head;

	while (curr) {
		Node* nextNode = curr->next;
		delete curr;
		curr = nextNode;
	}
	
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;

	// TODO: implement this function
	

	Node* curr = head;

	while (curr) {
		std::ostringstream currTempOss;
		currTempOss << std::fixed << curr->data.temperature;
		std::string currTemp = currTempOss.str();
		size_t decimalPos = currTemp.find('.');
		if (decimalPos != std::string::npos) {
			size_t lastKeep = currTemp.find_last_not_of('0', decimalPos + 1);
			currTemp.erase(lastKeep + 1);
		}
		if (!currTemp.empty() && currTemp.back() == '.') {
			currTemp.pop_back();
		}

		outputString += curr->data.id + " " + std::to_string(curr->data.year) + " " + std::to_string(curr->data.month) + " " + currTemp + "\n";
		if (curr->next) {
			//outputString += "\n";
			curr = curr->next;
		}
		else { 
			break;
		}
	}


	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
