#include <iostream>
#include <string>
#include <conio.h>

#include "List.h"
#include "BinInterface.h"
#include "OctInterface.h"

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGTH 77
#define ENTER 13

using namespace std;

int lastSelectedMenuLine = 0;

List *listes[3] = {new List(), new BinInterface(), new OctInterface()};

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

			case ARROW_LEFT:
				system("@cls||clear");

				return -1;

			case ARROW_RIGTH:
				system("@cls||clear");

				return -2;

			case ENTER:
				lastSelectedMenuLine = activeLine;
				system("@cls||clear");
				return activeLine;
		}

	}
}

void applyCommand(int command, List *list) {
	system("@cls||clear");

	switch (command)
	{

	case 0:
		int number;
		cout << "Введите число: ";
		cin >> number;
		list->push(number);
		break;

	case 1: {
		if (list->isEmpty()) {
			cout << "Лист пустой!";
			cin.get();

			break;
		}

		int listSize = list->getSize();

		string slecetElementMessage = "Выберите элемент:";

		string *commands = new string[listSize];

		for (int i = 0; i < listSize; i++)
		{
			commands[i] = list->getStringValue(list->get(i));
			commands[i] += " (";
			commands[i] += to_string(list->get(i));
			commands[i] += ")";
		}

		int index = menu(slecetElementMessage, commands, listSize);

		list->remove(index);

		break;
	}

	case 2: {
		if (list->isEmpty()) {
			cout << "Лист пустой!";
			cin.get();

			break;
		}

		int listSize = list->getSize();

		string slecetElementMessage = "Выберите элемент:";

		string *commands = new string[listSize];

		for (int i = 0; i < listSize; i++)
		{
			commands[i] = list->getStringValue(list->get(i));
			commands[i] += " (";
			commands[i] += to_string(list->get(i));
			commands[i] += ")";
		}

		int index = menu(slecetElementMessage, commands, listSize);

		list->edit(index);

		break;
	}

	case 3:
		list->load();
		break;

	case 4:
		list->save();
		break;

	case 5:
		exit(0);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string commands[] = {
		"Добавить элемент",
		"Удалить элемент",
		"Редактировать элемент",
		"Загрузить",
		"Сохранить",
		"\033[31mВыход\033[0m",
	};

	int listId = 0;
	List *activeList = listes[0];

	for (;;) {
		string status;
		
		switch (listId)
		{
		case 0:
			status += "Выбранный класс \033[36mList\033[0m\n";
			break;
		case 1:
			status += "Выбранный класс \033[33mBinInterface\033[0m\n";
			break;

		case 2:
			status += "Выбранный класс \033[35mOctInterface\033[0m\n";
			break;
		}

		status += activeList->toString();

		int command = menu(status, commands, sizeof(commands) / sizeof(string));

		switch (command)
		{

			case -1:
				listId = (listId == 0) ? 2 : listId - 1;
				break;

			case -2:
				listId = (listId >= 2) ? 0 : listId + 1;
				break;

			default:
				applyCommand(command, activeList);

		}

		activeList = listes[listId];

	}

}

