#include "Stack2.h"

Stack2::Stack2()
{
	Stack::Stack();
}

void Stack2::push(int number) {
	Stack::push(number);
}

int Stack2::pop() {
	return Stack::pop();
}

StackElement* Stack2::getHead() {
	return Stack::getHead();
}

Stack* Stack2::copy() {
	return Stack::copy();
}

void Stack2::print() {
	Stack::print();
}

bool Stack2::isEmpty() {
	return Stack::isEmpty();
}
void Stack2::setHead(StackElement* element) {
	Stack::setHead(element);
}


int Stack2::getResultValue() {
	StackElement *currnet = this->getHead();
	int counter = 0;

	while (currnet->getPrev())
	{
		counter = (currnet->getData() > currnet->getPrev()->getData()) ? counter + 1 : counter;
		currnet = currnet->getPrev();
	}

	return counter;
}
