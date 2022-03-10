#include "Stack3.h"

Stack3::Stack3()
{
	Stack::Stack();
}

void Stack3::push(int number) {
	Stack::push(number);
}

int Stack3::pop() {
	return Stack::pop();
}

Stack* Stack3::copy() {
	return Stack::copy();
}

StackElement* Stack3::getHead() {
	return Stack::getHead();
}

void Stack3::print() {
	Stack::print();
}

bool Stack3::isEmpty() {
	return Stack::isEmpty();
}

void Stack3::setHead(StackElement* element) {
	Stack::setHead(element);
}

int Stack3::getResultValue() {
	StackElement *current = this->getHead();
	int counter = 0;

	while (current->getPrev())
	{
		counter = (current->getData() > current->getPrev()->getData()) ? counter + 1 : counter;
		current = current->getPrev();
	}

	return counter;
}
