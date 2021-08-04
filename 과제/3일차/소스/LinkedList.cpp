#include "LinkedList.h"

int LinkedList::getLength() {
	return length;
}

void LinkedList::push(int value) {
	length++;
	if (!start)
		start = new Node(value);
	else {
		Node* now = start;
		while (now->next)
			now = now->next;
		now->next = new Node(value);
	}
}

int LinkedList::get(int index) {
	if (index < 0 || index >= length)
		return 0;

	Node* now = start;
	int i = 0;
	while (i++ != index)
		now = now->next;

	return now->data;
}

void LinkedList::set(int index, int value) {
	if (index < 0 || index >= length)
		return;

	Node* now = start;
	int i = 0;
	while (i++ != index)
		now = now->next;

	now->data = value;
}

int LinkedList::find(int value) {
	Node* now = start;
	int i = 0;
	while (now) {
		if (now->data == value)
			return i;
		now = now->next;
		i++;
	}
	return -1;
}

int LinkedList::count(int value) {
	Node* now = start;
	int i = 0;
	int cnt = 0;
	while (now) {
		if (now->data == value)
			cnt++;
		now = now->next;
		i++;
	}
	return cnt;
}

void LinkedList::remove(int index) {
	if (index < 0 || index >= length) {
		return;
	}
	if (index == length - 1 && length > 1) {
		Node* now = start;
		int i = 0;
		while (i++ < index)
			now = now->next;
		delete now->next;
		now->next = nullptr;
	}
	else if (index == 0) {
		Node* preStart = start;
		start = preStart->next;
		delete preStart;
	}
	else {

		Node* now = start;
		int i = 0;
		while (i++ != index - 1)
			now = now->next;

		Node* left = now;
		Node* right = now->next->next;
		delete left->next;
		left->next = right;
	}
	length--;
}

int& LinkedList::operator[](const int& index) {
	if (index < 0 || index >= length)
		throw std::out_of_range("out of index");

	Node* now = start;
	int i = 0;
	while (i++ != index)
		now = now->next;

	return now->data;
}

LinkedList LinkedList::clone() {
	LinkedList list;
	for (int i = 0; i < length; i++)
		list.push(get(i));
	return list;
}

void LinkedList::insert(int index, int value) {
	if (index == length - 1) {
		push(value);
		return;
	}
	if (index < 0 || index >= length) {
		return;
	}
	length++;
	if (index == 0) {
		Node* right = start;
		Node* newNode = new Node(value);
		newNode->next = right;
		start = newNode;
	}
	else {
		Node* now = start;
		int i = 0;
		while (i++ != index - 1)
			now = now->next;

		Node* left = now;
		Node* right = now->next;
		Node* newNode = new Node(value);
		newNode->next = right;
		left->next = newNode;
	}
}

std::ostream& operator<<(std::ostream& cout, LinkedList& list) {
	for (int i = 0; i < list.getLength(); i++)
		if (i)
			cout << ", " << list.get(i);
		else
			cout << list.get(i);
	return cout;
}