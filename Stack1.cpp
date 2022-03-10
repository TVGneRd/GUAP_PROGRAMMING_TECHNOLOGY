#include "Stack1.h"

int Stack1::getResultValue() {
	StackElement *currnet = this->getHead();
	int counter = 0;

	while (currnet->getPrev())
	{
		counter = (currnet->getData() > currnet->getPrev()->getData()) ? counter + 1 : counter;
		currnet = currnet->getPrev();
	}
	
	return counter;
}
