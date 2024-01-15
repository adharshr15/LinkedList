# include <string>
# include "Node.h"

using std::string;

Node::Node() : data(), next(nullptr) {
	// TODO: implement this function
	this->data.id = "";
	this->data.year = 0;
	this->data.month = 0;
	this->data.temperature = 0;

}

Node::Node(const Node& x) : data(), next(x.next) {
	data = x.data;
}


Node::Node(string id, int year, int month, double temperature) : data(), next(nullptr) {
	// TODO: implement this function
	this->data.id = id;
	this->data.year = year;
	this->data.month = month;
	this->data.temperature = temperature;
}

Node& Node::operator=(const Node& b) {
	Node* newNode = new Node();
	newNode->data = b.data;
	newNode->next = b.next;
	return *this;
}

bool Node::operator<(const Node& b) {	
	return this->data < b.data;
}
