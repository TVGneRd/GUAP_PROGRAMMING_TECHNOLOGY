#pragma once

#include <iostream>

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGTH 77
#define ENTER 13

using namespace std;

template <typename T>void fill(T *array, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "Введите " << (i + 1) << " элемент: ";
		cin >> array[i];
		//array[i] = rand() % 100;
	}
	system("@cls||clear");
}

template <typename T>void print(T *array, int size) {
	cout << "[";

	for (int i = 0; i < size; i++)
	{
		if (i) cout << ", ";
		cout << array[i];
	}

	cout << "]" << endl;
}

int menu(string status, string* commands, size_t commandsLength) {

	int activeLine = 0;

	while (true)
	{
		system("@cls||clear");

		cout << status << endl;

		for (size_t i = 0; i < commandsLength; i++)
		{
			if (activeLine == i) cout << "\033[36m";
			cout << i + 1 << ". " << commands[i] << "\033[0m" << endl;
		}

		int command = _getch();
		if (command == 224) command = _getch();

		switch (command)
		{
		case ARROW_DOWN:
			activeLine = (activeLine >= commandsLength - 1) ? 0 : activeLine + 1;
			break;

		case ARROW_UP:
			activeLine = (activeLine == 0) ? commandsLength - 1 : activeLine - 1;
			break;

		case ARROW_LEFT:
			system("@cls||clear");

			return -1;

		case ARROW_RIGTH:
			system("@cls||clear");

			return -2;

		case ENTER:
			system("@cls||clear");
			return activeLine;
		}

	}
}

