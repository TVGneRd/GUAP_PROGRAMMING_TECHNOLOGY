#include "StackElement.h"
#pragma once
class Stack 
{
public:
	Stack();
	virtual void push(int element);
	virtual int pop();
	virtual void print();
	virtual bool isEmpty();
	virtual StackElement* getHead();
	virtual void setHead(StackElement* element);
	virtual Stack* copy();

private:
	StackElement *head;
};


