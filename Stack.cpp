#include <iostream>
#include "Stack.h"

Stack::Stack() {};

Stack* Stack::copy()
{
	Stack *newStack = new Stack;
	newStack->head = new StackElement(*this->head);
	StackElement *current = newStack->head;

	while (current)
	{
		StackElement *prev = current->getPrev();

		if (prev) {
			StackElement *tmp = new StackElement(*prev);
			current->setPrev(tmp);
			current = tmp;
		} else {
			break;
		}
	}

	std::cout << "Очередь скопирована" << std::endl;

	return newStack;
}

void Stack::setHead(StackElement* element) {
	this->head = element;
}

void Stack::push(int number) {
	StackElement *element = new StackElement(number, head);
	this->head = element;
}

int Stack::pop() {
	if (isEmpty()) return -1;

	StackElement *last = this->head;
	StackElement *prev = last;

	while (last)
	{ // переходим в конец очереди current будет предпоследним prev последним
		if (last->getPrev()) {
			prev = last;
			last = last->getPrev();
		} else {
			break;
		}
	}

	int value = last->getData();
	prev->setPrev(nullptr);

	delete last;

	return value;
}

StackElement* Stack::getHead() {
	return head;
}


void Stack::print() {
	StackElement *current = this->head;

	while (current)
	{
		std::cout << current->getData();

		current = current->getPrev();

		if (current) std::cout << " -> ";
	}

	std::cout << std::endl;

}

bool Stack::isEmpty() {
	return this->head == nullptr;
}


