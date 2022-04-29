#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <string> 

#include "List.h"

using namespace std;

List::List()
{

}

List::~List()
{
	
}

void List::load()
{
	ifstream fin("input.txt");

	fin >> size;

	data = (int *)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		fin >> data[i];
	}

	fin.close();

	cout << "\033[32mЗагружено " << size << " элементов!\033[0m" << endl;
	cin.get();

}

void List::save()
{
	if (isEmpty()) {
		cout << "\033[31mЛист пустой!\033[0m" << endl;
		cin.get();

		return;
	}

	FILE *file;

	ofstream fin("input.txt");

	fin << size;
	fin << endl;

	for (int i = 0; i < size; i++) {
		fin << data[i];
		fin << endl;
	}

	fin.close();

	cout << "\033[32mСохранено\033[0m" << endl;
	cin.get();

}

void List::push(int number)
{
	size++;
	data = (int *)realloc(data, (size+1) * sizeof(int));
	data[size-1] = number;
}

void List::remove(int index)
{
	if (isEmpty()) return;

	if (index >= size) {
		cout << "\033[31mЧисло не найдено!\033[0m" << endl;
		cin.get();

		return;
	}
	
	for (int i = index+1; i < size; i++) {
		data[i - 1] = data[i];
	}

	size--;
}

void List::edit(int index)
{
	if (isEmpty()) return;

	if (index >= size) {
		cout << "\033[31mЧисло не найдено!\033[0m" << endl;
		cin.get();

		return;
	}

	int number;

	cout << "Введите новое число: ";
	cin >> number;

	data[index] = number;
}

int List::get(int index)
{
	if (index >= size) {
		cout << "\033[31mЧисло не найдено!\033[0m" << endl;
		cin.get();

		return 0;
	}
	return data[index];
}

int List::getSize()
{
	return size;
}

bool List::isEmpty()
{
	return size == 0;
}

string List::toString()
{
	string str = "[";

	for (int i = 0; i < size; i++)
	{
		str += this->getStringValue(data[i]);
		if (i < size - 1) str += ", ";
	}

	str += "]\n";

	return str;
}

string List::getStringValue(int data)
{
	return std::to_string(data);
}
