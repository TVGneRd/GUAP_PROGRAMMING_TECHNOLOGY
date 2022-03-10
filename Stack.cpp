#include <iostream>
#include "Stack.h"

Stack::Stack() {};

Stack* Stack::copy()
{
	Stack *newStack = new Stack;
	newStack->head = new StackElement(*this->head);
	StackElement *currnet = newStack->head;

	while (currnet)
	{
		StackElement *prev = currnet->getPrev();

		if (prev) {
			StackElement *tmp = new StackElement(*prev);
			currnet->setPrev(tmp);
			currnet = tmp;
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
	StackElement *tmp = this->head;

	int value = this->head->getData();
	this->head = this->head->getPrev();
	delete tmp;

	return value;
}

StackElement* Stack::getHead() {
	return head;
}


void Stack::print() {
	StackElement *currnet = this->head;

	while (currnet)
	{
		std::cout << currnet->getData();

		currnet = currnet->getPrev();

		if (currnet) std::cout << " -> ";
	}

	std::cout << std::endl;

}

bool Stack::isEmpty() {
	return this->head == nullptr;
}


