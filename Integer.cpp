#include "Integer.h"
#include <iostream>

using namespace std;

Integer & Integer::operator--()
{
	int num;

	cout << "������� �����: ";
	cin >> num;

	this->number -= num;

	return *this;
}

Integer Integer::operator--(int)
{
	this->number--;
	return *this;
}

Integer & operator++(Integer& integer)
{
	int num;

	cout << "������� �����: ";
	cin >> num;

	integer.number += num;

	return integer;
}

Integer operator++(Integer &integer, int)
{
	integer.number++;

	return integer;
}

int Integer::operator!()
{
	return -this->number;
}

int Integer::getData() {
	return number;
}