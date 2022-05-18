#include <iostream>
#include <string>
#include <conio.h>

#include "utilities.h"
#include "Sort.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string commands[] = {
		"Тип int",
		"Тип float",
		"Тип double",
		"Тип char",
		"\033[31mВыход\033[0m",
	}; 

	for (;;) {
		system("@cls||clear");
		
		int size;

		try {
			cout << "Введите размер массива: ";
			cin >> size;

			if (size < 2) throw string("\033[31mРазмер массива должен быть больше 2-х\033[0m");

		} catch (string myNum) {
			cout << myNum;
			cout << endl << endl << "Нажмите любую клавишу" << endl;
			_getch();

			continue;
		}

		string status = "Выбреите тип списка:";
		
		int command = menu(status, commands, sizeof(commands) / sizeof(string));

		switch (command)
		{

			case 0: {
				
				int *arr = new int[size];

				fill<int>(arr, size);

				cout << "Массив до сортировки:    ";
				print<int>(arr, size);

				sort<int>(arr, size);

				cout << endl << "Массив после сортировки: ";
				print<int>(arr, size);

				break;
			}

			case 1: {

				float *arr = new float[size];

				fill<float>(arr, size);

				cout << "Массив до сортировки:    ";
				print<float>(arr, size);

				sort<float>(arr, size);

				cout << endl << "Массив после сортировки: ";
				print<float>(arr, size);

				break;
			}

			case 2: {

				double *arr = new double[size];

				fill<double>(arr, size);

				cout << "Массив до сортировки:    ";
				print<double>(arr, size);

				sort<double>(arr, size);

				cout << endl << "Массив после сортировки: ";
				print<double>(arr, size);

				break;
			}

			case 3: {

				char *arr = new char[size];

				fill<char>(arr, size);

				cout << "Массив до сортировки:    ";
				print<char>(arr, size);

				sort<char>(arr, size);

				cout << endl << "Массив после сортировки: ";
				print<char>(arr, size);

				break;
			}

			case 4: {
				exit(0);
			}
		}

		cout << endl << endl << "Нажмите любую клавишу" << endl;
		_getch();
	}

}

