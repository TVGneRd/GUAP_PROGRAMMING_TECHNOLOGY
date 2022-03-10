#include "Stack1.h"

int Stack1::getResultValue() {
	StackElement *current = this->getHead();
	int counter = 0;

	while (current->getPrev())
	{
		counter = (current->getData() > current->getPrev()->getData()) ? counter + 1 : counter;
		current = current->getPrev();
	}
	
	return counter;
}
