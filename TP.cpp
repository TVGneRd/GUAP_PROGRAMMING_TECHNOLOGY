#include <iostream>
#include <string>
#include <conio.h>

#include "Stack.h"
#include "Integer.h"

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGTH 77
#define ENTER 13

using namespace std;

Stack* stack = new Stack();
int lastSelectedMenuLine = 0;

void backLoop() {
	cout << endl << "Нажмите любую клавишу для выхода в меню" << endl;
	_getch();
}


int menu(string status, string* commands, size_t commandsLength) {

	int activeLine = lastSelectedMenuLine;

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

			case ENTER:
				lastSelectedMenuLine = activeLine;
				system("@cls||clear");
				return activeLine;
		}

	}
}

void IntegerLoop() {
	int num;

	cout << "Введите начальное число: ";
	cin >> num;
	system("@cls||clear");

	Integer integer(num);

	string commands[] = {
		"Вычесть число (--int)",
		"Вычесть единицу (int--)",
		"Прибавть число (++int)",
		"Прибавть единицу (int++)",
		"Получить отрицательное значение (!)",
		"\033[31mВернуться в меню\033[0m"
	};
	
	lastSelectedMenuLine = 0;

	while (true)
	{
		string status = "Значение класса Integer: \033[31m" + to_string(integer.getData()) + "\033[0m";

		int command = menu(status, commands, 6);

		switch (command)
		{
			case 0:
				--integer;
				break;
			case 1:
				integer--;
				break;
			case 2:
				++integer;
				break;
			case 3:
				integer++;
				break;
			case 4:
				cout << !integer;
				backLoop();
				break;
			case 5:
				return;
		}
	}
}

void StackLoop() {

	string commands[] = {
		"Добавить элемент в очередь (+=)",
		"Извлечь элемент из очереди (-=)",
		"Прибавть число ко всем элементам очереди (+)",
		"Отнять число от всех элементов очереди (-)",
		"Умножить очередь на число (*)",
		"Разделить очередь на число (/)",
		"Продублировать очередь (*=)",
		"Очистить очередь (/=)",
		"\033[31mВернуться в меню\033[0m"
	};

	lastSelectedMenuLine = 0;

	int num = 0;

	while (true)
	{
		string status = "Значение класса Stack: \033[31m" + stack->toString() + "\033[0m";

		int command = menu(status, commands, 9);

		switch (command)
		{
		case 0:
			cout << "Введите число: ";
			cin >> num;

			*stack += num;
			break;

		case 1:
			*stack -= 1;
			break;

		case 2:
			cout << "Введите число: ";
			cin >> num;

			*stack = *stack + num;
			break;

		case 3:
			cout << "Введите число: ";
			cin >> num;

			*stack = *stack - num;
			break;

		case 4:
			cout << "Введите число: ";
			cin >> num;

			*stack = *stack * num;
			break;
		case 5:
			cout << "Введите число: ";
			cin >> num;

			*stack = *stack / num;
			break;
		case 6:
			*stack *= 2;
			break;
		case 7:
			*stack /= 1;
			break;
		case 8:
			return;
		}
	}
	
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int command = 0;
	int activeTask = 0;

	while (true)
	{
		system("@cls||clear");
		cout << "Выберите задание:" << endl << endl;

		for (int i = 0; i < 2; i++)
		{
			if (activeTask == i) cout << "\033[36m";
			cout << "Задание " << (i+1) << "\033[0m" << endl;
		}

		command = _getch();
		if (command == 224) command = _getch();

		switch (command)
		{

		case ARROW_DOWN:
		case ARROW_UP:
			activeTask = !activeTask;
			break;

		case ENTER:
			system("@cls||clear");

			if (activeTask) {
				StackLoop();
			} else {
				IntegerLoop();
			}
		}
	}

	
}

