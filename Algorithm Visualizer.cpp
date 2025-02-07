#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

//@brief Writes given array to the console using self determined styling.
//
//@param targetArray: Integer array to be displayed
//@param targetArraySize: Size of target array being passed
//@param activeElements: Elements indexes that are being interacted with at the moment -- Yellow
//@param selectedElements: Elements indexes that are being moved/changed at the moment -- Red
void DisplayArray(int targetArray[], int targetArraySize, int activeElement = -1, int selectedElement = -1)
{
	const string RED = "\033[31m";
	const string YELLOW = "\033[33m";
	const string GREEN = "\033[32m";
	const string WHITE = "\033[37m";

	int len = targetArraySize;

	system("cls");

	cout << "[";

	for (int i = 0; i < len; i++)
	{
		// highlight active elements in yellow, selected elements in red
		if (selectedElement == i && selectedElement != -1)
		{
			cout << RED << targetArray[i] << WHITE;
		}
		else if (activeElement == i && activeElement != -1)
		{
			cout << YELLOW << targetArray[i] << WHITE;
		}
		else
		{
			cout << targetArray[i];
		}

		// prevent comma at end of array
		if (i != len - 1)
		{
			cout << ",";
		}
	}

	cout << "]";
}

//@brief Sort a given array using bubble sort algorithm.
//
//@param targetArray: Integer array to be sorted.
//@param targetArraySize: Size of given integer array.
void BubbleSort(int targetArray[], int targetArraySize)
{
	const int sleepTime = 300;

	int activeElement;
	int selectedElement;

	for (int i = 0; i < targetArraySize - 1; i++)
	{
		for (int j = 0; j < targetArraySize - i - 2; j++)
		{
			activeElement = j;

			DisplayArray(targetArray, targetArraySize, activeElement);

			sleep_for(milliseconds(sleepTime));

			if (targetArray[j] > targetArray[j + 1])
			{
				selectedElement = j + 1;

				DisplayArray(targetArray, targetArraySize, activeElement, selectedElement);

				sleep_for(milliseconds(sleepTime));

				int temp = targetArray[j];
				targetArray[j] = targetArray[j + 1];
				targetArray[j + 1] = temp;
			}

			activeElement = j + 1;
			selectedElement = j;

			DisplayArray(targetArray, targetArraySize, activeElement, selectedElement);

			sleep_for(milliseconds(sleepTime));
		}
	}
}


//@brief Sort a given integer array using the selection sort algorithm.
//
//@param targetArray: The integer array to be sorted.
//@param targetArraySize: The length of the integer array.
void SelectionSort(int targetArray[], int targetArraySize)
{
	const int sleepTime = 750;

	int activeElement;
	int selectedElement;

	for (int i = 0; i < targetArraySize; i++)
	{
		int min = i;

		for (int j = 0 + i; j < targetArraySize; j++)
		{
			activeElement = j;
			selectedElement = min;

			DisplayArray(targetArray, targetArraySize, activeElement, selectedElement);

			sleep_for(milliseconds(sleepTime));

			if (targetArray[j] < targetArray[min])
			{
				min = j;

				DisplayArray(targetArray, targetArraySize, activeElement, selectedElement);
			}
		}

		int temp = targetArray[i];
		targetArray[i] = targetArray[min];
		targetArray[min] = temp;

		selectedElement = i;

		DisplayArray(targetArray, targetArraySize, activeElement, selectedElement);

		sleep_for(milliseconds(sleepTime));
	}
}


//@brief Sort a given array using the insertion sort algorithm.
//
//@param targetArray: The integer array to be sorted.
//@param targetArraySize: The size of the given integer array.
void InsertionSort(int targetArray[], int targetArraySize)
{
	const int sleepTime = 1000;

	int activeElement;
	int selectedElement;

	for (int i = 1; i < targetArraySize; i++)
	{
		int temp = targetArray[i];
		int j = i - 1;

		activeElement = i;

		DisplayArray(targetArray, targetArraySize, activeElement);

		sleep_for(milliseconds(sleepTime));

		while (j >= 0 && targetArray[j] > temp)
		{
			activeElement = j + 1;
			selectedElement = j;

			DisplayArray(targetArray, targetArraySize, activeElement, selectedElement);

			sleep_for(milliseconds(sleepTime));

			targetArray[j + 1] = targetArray[j];
			targetArray[j] = temp;

			activeElement = j;
			selectedElement = j + 1;

			DisplayArray(targetArray, targetArraySize, activeElement, selectedElement);

			sleep_for(milliseconds(sleepTime));

			j--;
		}
	}
}

int main()
{
	int numbers[] = {9,2,1,5,6,4,7,8,8,2};

	InsertionSort(numbers, sizeof(numbers) / sizeof(numbers[0]));
}
