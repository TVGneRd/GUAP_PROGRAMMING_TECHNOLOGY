#pragma once
#include <string> 
#include <iostream>

using namespace std;

class List {
public:
	List();
	~List();
	
	void push(int number);
	void remove(int index);
	void edit(int index);

	void save();
	void load();

	int get(int index);
	int getSize();

	bool isEmpty();

	string toString();

	virtual string getStringValue(int data);

private:
	int *data;
	int size;
};