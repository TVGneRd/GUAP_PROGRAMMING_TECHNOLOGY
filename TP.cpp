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

void backLoop() {
	cout << endl << "Нажмите любую клавишу для выхода в меню" << endl;
	_getch();
}

//template <typename StackLike>
//void pushLoop(StackLike stack) {
//	int n;
//
//	do
//	{
//		cout << "Введите число: ";
//		cin >> n;
//
//		stack->push(n);
//
//		cout << "\033[32mУспешно добавлено.\033[0m" << endl;
//		cout << endl << "Нажмите любую клавишу для выхода в меню или ENTER чтобы добавить еще" << endl;
//	} while (_getch() == ENTER);
//	
//}
//
//template <typename StackLike>
//void popLoop(StackLike stack) {
//
//	if (stack->isEmpty()) {
//		cout << "Очередь пуста."  << endl;
//	}
//	else 
//	{
//		cout << "Результат: " << stack->pop() << endl;
//	}
//
//	backLoop();
//}
//
//template <typename StackLike>
//void printLoop(StackLike stack) {
//	if (stack->isEmpty()) {
//		cout << "Очередь пуста." << endl;
//	}
//	else
//	{
//		stack->print();
//	}
//
//	backLoop();
//}
//
//template <typename StackLike>
//void calculateLoop(StackLike stack) {
//	if (stack->isEmpty()) {
//		cout << "Очередь пуста." << endl;
//	}
//	else
//	{
//		cout << "Число элементов, значение которых превышает значение предыдущего элемента: " << stack->getResultValue() << endl;
//
//	}
//
//	backLoop();
//}
//
//template <typename StackLike>
//void pasteLoop(StackLike *stack) {
//	StackElement *current = buffer->getHead();
//
//	// доходим до предпоследнего элемента
//	while (current->getPrev()) {
//		current = current->getPrev();
//	}
//
//	current->setPrev(stack->getHead());
//	stack->setHead(buffer->getHead());
//
//	buffer = nullptr;
//}
//
//
//template <typename StackLike>
//void copyLoop(StackLike *stack) {
//	buffer = stack->copy();
//}
//
//template <typename StackLike>
//void applyCommand(int command, StackLike stack) {
//	switch (command)
//	{
//	case 0:
//		pushLoop(stack);
//		break;
//	case 1:
//		popLoop(stack);
//		break;
//	case 2:
//		printLoop(stack);
//		break;
//	case 3:
//		calculateLoop(stack);
//		break;
//	case 4:
//		if (stack->isEmpty()) {
//			cout << "Очередь пуста." << endl;
//			break;
//		}
//		copyLoop(stack);
//
//		backLoop();
//
//		break;
//
//	case 5:
//		pasteLoop(stack);
//		cout << "\033[32mУспешно вставлено\033[0m" << endl;
//
//		backLoop();
//		break;
//
//	case 6:
//		exit(0);
//		break;
//	}
//}

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


		case ENTER:
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
		"Вычесть число",
		"Вычесть еденицу",
		"Прибавть число",
		"Прибавть еденицу",
		"Получить отрицательное значение",
		"\033[31mВернуться в меню\033[0m"
	};

	while (true)
	{
		string status = "Значение класса Integer: \033[31m" + std::to_string(integer.getData()) + "\033[0m";

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
				integer--;
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

	int activeLine = 0;
	int command = 0;

	string commands[] = {
		"Добавить элемент в очередь",
		"Извлечь элемент из очереди",
		"Вывод очереди на экран",
		"Выполнение расчета по варианту",
		"Создание копии очереди",
		"Слияние двух очередей",
		"Выход из программы"
	};

	int commandsLength = sizeof(commands) / sizeof(string);
	
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

