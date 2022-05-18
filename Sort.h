#pragma once

#include <iostream>
#include "utilities.h"
#include "windows.h" 

using namespace std;

template <typename T>void sortPrint(T *array, int size, int newIndex, int oldIndex) {
	cout << "\r";

	cout << "[";

	for (int i = 0; i < size; i++)
	{
		if (i) cout << ", ";
		if(i == newIndex) cout << "\033[31m";
		if(i == oldIndex) cout << "\033[32m";

		cout << array[i];

		cout << "\033[0m";
	}

	cout << "]";
}

template <typename T>void sort(T * arr, int size)
{
	int d = size / 2;

	cout << "\n";

	while (d > 0)
	{
		for (int i = 0; i < size - d; i++)
		{
			int j = i;

			while (j >= 0 && arr[j] > arr[j + d])
			{
				T count = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = count;

				sortPrint<T>(arr, size, j, j + d);
				Sleep(2500 / log2(size) / log2(size));

				j--;
			}
		}

		d = d / 2;
	}

	cout << "\r\n";
}