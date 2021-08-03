#pragma once
struct Node {
	Node(int value) : data(value) {}
	int data;
	Node* next = nullptr;
};

class LinkedList {
private:
	Node* start = nullptr;
	int length = 0;

public:
	int getLength();
	int get(int);
	void set(int, int);
	void push(int);

	int find(int);
	int count(int);
	void insert(int, int);
	void remove(int);
};