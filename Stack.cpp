#include "Stack.h"

Stack::Stack() {};

void Stack::setHead(StackElement* element) {
	this->head = element;
}

StackElement* Stack::getHead() {
	return head;
}

bool Stack::isEmpty() {
	return this->head == nullptr;
}

void Stack::operator+=(int el) {
	StackElement *element = new StackElement(el, head);
	this->head = element;
}

Stack Stack::operator+(int el) {
	StackElement *last = this->head;

	do 
	{ 
		*last += el;
	} while (last = last->getPrev());

	return *this;
}

void Stack::pop() {
	if (isEmpty()) return;

	StackElement *last = this->head;
	StackElement *prev = last;
	
	if (!last->getPrev()) {
		// если в стеке 1 элемент
		head = nullptr;
		delete last;
		return;
	}

	while (last)
	{ // переходим в конец очереди current будет предпоследним prev последним
		if (last->getPrev()) {
			prev = last;
			last = last->getPrev();
		}
		else {
			break;
		}
	}

	prev->setPrev(nullptr);

	delete last;
}

void Stack::operator-=(int el) {
	pop();
}

Stack Stack::operator-(int el) {
	StackElement *last = this->head;

	do
	{
		*last += -el;
	} while (last = last->getPrev());

	return *this;
}

void Stack::operator*=(int el)
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
		}
		else {
			break;
		}
	}

	current = newStack->getHead();
	
	while (current->getPrev()) {
		current = current->getPrev();
	}
	
	current->setPrev(this->getHead());
	this->setHead(newStack->getHead());
}

Stack Stack::operator*(int el)
{
	StackElement *last = this->head;

	do
	{
		*last *= el;
	} while (last = last->getPrev());

	return *this;
}

void Stack::operator/=(int el)
{
	StackElement *last;

	while(last = this->head)
	{
		pop();
	} 
}

Stack Stack::operator/(int el)
{
	StackElement *last = this->head;

	do
	{
		*last /= el;
	} while (last = last->getPrev());
	return *this;
}

string Stack::toString() {
	StackElement *current = this->head;
	string result = "";

	while (current)
	{
		result += std::to_string(current->getData());

		current = current->getPrev();

		if (current) result += " <=> ";
	}

	return result;
}


