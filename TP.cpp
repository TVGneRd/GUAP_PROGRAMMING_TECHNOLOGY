#include <iostream>
#include <string>
#include <conio.h>

#include "Stack.h"
#include "Stack1.h"
#include "Stack2.h"
#include "Stack3.h"


#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGTH 77
#define ENTER 13

using namespace std;

template <typename StackLike>
StackLike* selectedStack;

Stack1* stack1;
Stack2* stack2;
Stack3* stack3;

Stack* buffer;

void backLoop() {
	cout << endl << "Нажмите любую клавишу для выхода в меню" << endl;
	_getch();
}

template <typename StackLike>
void pushLoop(StackLike stack) {
	int n;

	do
	{
		cout << "Введите число: ";
		cin >> n;

		stack->push(n);

		cout << "\033[32mУспешно добавлено.\033[0m" << endl;
		cout << endl << "Нажмите любую клавишу для выхода в меню или ENTER чтобы добавить еще" << endl;
	} while (_getch() == ENTER);
	
}

template <typename StackLike>
void popLoop(StackLike stack) {

	if (stack->isEmpty()) {
		cout << "Очередь пуста."  << endl;
	}
	else 
	{
		cout << "Результат: " << stack->pop() << endl;
	}

	backLoop();
}

template <typename StackLike>
void printLoop(StackLike stack) {
	if (stack->isEmpty()) {
		cout << "Очередь пуста." << endl;
	}
	else
	{
		stack->print();
	}

	backLoop();
}

template <typename StackLike>
void calculateLoop(StackLike stack) {
	if (stack->isEmpty()) {
		cout << "Очередь пуста." << endl;
	}
	else
	{
		StackElement *currnet = stack->getHead();
		int counter = 0;

		while (currnet->getPrev())
		{
			counter = (currnet->getData() > currnet->getPrev()->getData()) ? counter + 1 : counter;
			currnet = currnet->getPrev();
		}

		cout << "Число элементов, значение которых превышает значение предыдущего элемента: " << counter << endl;

	}

	backLoop();
}

template <typename StackLike>
void pasteLoop(StackLike *stack) {
	StackElement *currnet = buffer->getHead();

	// доходим до предпоследнего элемента
	while (currnet->getPrev()) {
		currnet = currnet->getPrev();
	}

	currnet->setPrev(stack->getHead());
	stack->setHead(buffer->getHead());

	buffer = nullptr;
}


template <typename StackLike>
void copyLoop(StackLike *stack) {
	buffer = stack->copy();
}

template <typename StackLike>
void applyCoomand(int command, StackLike stack) {
	switch (command)
	{
	case 0:
		pushLoop(stack);
		break;
	case 1:
		popLoop(stack);
		break;
	case 2:
		printLoop(stack);
		break;
	case 3:
		calculateLoop(stack);
		break;
	case 4:
		if (stack->isEmpty()) {
			cout << "Очередь пуста." << endl;
			break;
		}
		copyLoop(stack);

		backLoop();

		break;

	case 5:
		pasteLoop(stack);
		cout << "\033[32mУспешно вставлено\033[0m" << endl;

		backLoop();
		break;

	case 6:
		exit(0);
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	stack1 = new Stack1();
	stack2 = new Stack2();
	stack3 = new Stack3();

	int activeLine = 0;
	int activeStack = 0;
	int command = 0;

	string stackNames[] = {
		"\033[31mОчередь #1\033[0m",
		"\033[32mОчередь #2\033[0m",
		"\033[33mОчередь #3\033[0m",
	};

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

	while (true)
	{
		system("@cls||clear");

		cout << "Выбранная очередь: " << stackNames[activeStack] << " ";

		if (buffer) {
			cout << "\033[34m(Имеется копия в буффере)\033[0m";
		}

		cout << endl << endl;

		for (int i = 0; i < commandsLength; i++)
		{
			if (activeLine == i) cout << "\033[36m";
			cout << i + 1 << ". " << commands[i] << "\033[0m" << endl;
		}

		command = _getch();
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
				activeStack = (activeStack == 0) ? 2 : activeStack - 1;
				break;

			case ARROW_RIGTH:
				activeStack = (activeStack == 2) ? 0 : activeStack + 1;
				break;

			case ENTER: 
				system("@cls||clear");
				switch (activeStack)
				{
					case 0:
						selectedStack<Stack1> = stack1;
						applyCoomand(activeLine, selectedStack<Stack1>);
						break;
					case 1:
						selectedStack<Stack2> = stack2;
						applyCoomand(activeLine, selectedStack<Stack2>);
						break;
					case 2:
						selectedStack<Stack3> = stack3;
						applyCoomand(activeLine, selectedStack<Stack3>);
						break;
				}
		}

	}
}

