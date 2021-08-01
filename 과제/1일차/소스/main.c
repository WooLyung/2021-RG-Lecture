#include <stdio.h>
#include "LinkedList.h"

int main() {
	LinkedList list = { null, 0 };
	pushLinkedList(&list, 1);
	pushLinkedList(&list, 2);
	pushLinkedList(&list, 3);
	pushLinkedList(&list, 4);
	insertLinkedList(&list, 0, 2);
	insertLinkedList(&list, 2, 5);

	for (int i = 0; i < list.length; i++)
		printf("%d\n", getLinkedList(&list, i));
}