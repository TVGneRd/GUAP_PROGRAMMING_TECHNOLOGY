#pragma once

#include <iostream>
#include <sstream>

#include "StackElement.h"

using namespace std;

class Stack 
{
public:
	Stack();

	void operator+=(int el);
	Stack operator+(int el);

	void operator-=(int el);
	Stack operator-(int el);

	void operator*=(int el);
	Stack operator*(int el);

	void operator/=(int el);
	Stack operator/(int el);

	string toString();
	void setHead(StackElement* element);
	StackElement* getHead();
	void pop();

	bool isEmpty();

private:
	StackElement *head;
};


