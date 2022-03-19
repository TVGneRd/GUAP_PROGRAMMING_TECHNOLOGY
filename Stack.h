#include "StackElement.h"
#pragma once

class Stack 
{
public:
	Stack();
	void push(int element);
	int pop();
	void print();
	bool isEmpty();
	StackElement* getHead();
	void setHead(StackElement* element);
	Stack* copy();

	void operator+=(StackElement el); 
	void operator+(StackElement el);

	void operator-=(StackElement el);
	void operator-(StackElement el);

	void operator*=(StackElement el);
	void operator*(StackElement el);

	void operator/=(StackElement el);
	void operator/(StackElement el);

private:
	StackElement *head;
};


