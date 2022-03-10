#include "StackElement.h"

StackElement::StackElement(int data, StackElement *prev) {
	this->data = data;
	this->prev = prev;
}

StackElement::StackElement(const StackElement &stackElement) {
	this->data = stackElement.data;
	this->prev = stackElement.prev;
}

StackElement::~StackElement() {
	this->data = 0;
	this->prev = nullptr;
}

int StackElement::getData() {
	return data;
}

StackElement* StackElement::getPrev() {
	return prev;
}

void StackElement::setPrev(StackElement* prev) {
	this->prev = prev;
}
