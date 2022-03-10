#include "Stack.h"

class Stack3 : private Stack
{
public:
	Stack3();
	void push(int element);
	int pop();
	void print();
	bool isEmpty();
	StackElement* getHead();
	void setHead(StackElement* element);
	Stack* copy();
	int getResultValue();

private:
};