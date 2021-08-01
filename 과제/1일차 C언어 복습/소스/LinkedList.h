#include <stdlib.h>
#define null 0

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct LinkedList {
	Node* start;
	int length;
} LinkedList;

void pushLinkedList(LinkedList* list, int value) {
	list->length++;
	if (list->start == null) {
		list->start = (Node*)malloc(sizeof(Node));
		list->start->data = value;
		list->start->next = null;
	}
	else {
		Node* now = list->start;
		while (now->next != null)
			now = now->next;

		now->next = (Node*)malloc(sizeof(Node));
		now->next->data = value;
		now->next->next = null;
	}
}

int getLinkedList(LinkedList* list, int index) {
	if (index < 0 || index >= list->length)
		return null;

	Node* now = list->start;
	int i = 0;
	while (i++ != index)
		now = now->next;

	return now->data;
}

void setLinkedList(LinkedList* list, int index, int value) {
	if (index < 0 || index >= list->length)
		return;

	Node* now = list->start;
	int i = 0;
	while (i++ != index)
		now = now->next;

	now->data = value;
}

int findLinkedList(LinkedList* list, int value) {
	Node* now = list->start;
	int i = 0;
	while (now != null) {
		if (now->data == value)
			return i;
		now = now->next;
		i++;
	}
	return -1;
}

int countLinkedList(LinkedList* list, int value) {
	Node* now = list->start;
	int i = 0;
	int cnt = 0;
	while (now != null) {
		if (now->data == value)
			cnt++;
		now = now->next;
		i++;
	}
	return cnt;
}

void insertLinkedList(LinkedList* list, int index, int value) {
	if (index == list->length - 1) {
		pushLinkedList(list, value);
		return;
	}
	if (index < 0 || index >= list->length) {
		return;
	}

	list->length++;
	if (index == 0) {
		Node* right = list->start;
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = value;
		newNode->next = right;
		list->start = newNode;
	}
	else {
		Node* now = list->start;
		int i = 0;
		while (i++ != index - 1)
			now = now->next;

		Node* left = now;
		Node* right = now->next;
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = value;
		newNode->next = right;
		left->next = newNode;
	}
}