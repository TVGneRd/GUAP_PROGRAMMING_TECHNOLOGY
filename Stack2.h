#include "Stack.h"

class Stack2 : protected Stack
{
public:
	Stack2();
	void push(int element);
	int pop();
	void print();
	bool isEmpty();
	StackElement* getHead();
	void setHead(StackElement* element);
	Stack* copy();


private:
};

