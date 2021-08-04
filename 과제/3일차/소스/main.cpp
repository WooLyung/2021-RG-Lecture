#include <iostream>
#include "LinkedList.h"

int main() {
	LinkedList list;
	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	list.push(5);
	list.push(6);

	LinkedList list2 = list.clone();

	std::cout << list2 << std::endl;
}