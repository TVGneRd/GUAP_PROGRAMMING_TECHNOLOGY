#pragma once

class StackElement {
public:
	StackElement(int data, StackElement *prev);
	StackElement(const StackElement &stackElement);

	~StackElement();
	int getData();
	void operator+=(int num);
	void operator*=(int num);
	void operator/=(int num);

	StackElement* getPrev();
	void setPrev(StackElement* prev);

private:
	int data;
	StackElement *prev;
};