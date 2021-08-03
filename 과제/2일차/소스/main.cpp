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

	list.remove(4);

	for (int i = 0; i < list.getLength(); i++)
		std::cout << list.get(i) << std::endl;
}