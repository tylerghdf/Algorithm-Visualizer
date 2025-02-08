#include <thread>
#include <chrono>
#include "visualization.h"
#include "intarrayalgorithm.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

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

			DisplayIntArray(targetArray, targetArraySize, activeElement);

			sleep_for(milliseconds(sleepTime));

			if (targetArray[j] > targetArray[j + 1])
			{
				selectedElement = j + 1;

				DisplayIntArray(targetArray, targetArraySize, activeElement, selectedElement);

				sleep_for(milliseconds(sleepTime));

				int temp = targetArray[j];
				targetArray[j] = targetArray[j + 1];
				targetArray[j + 1] = temp;
			}

			activeElement = j + 1;
			selectedElement = j;

			DisplayIntArray(targetArray, targetArraySize, activeElement, selectedElement);

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

			DisplayIntArray(targetArray, targetArraySize, activeElement, selectedElement);

			sleep_for(milliseconds(sleepTime));

			if (targetArray[j] < targetArray[min])
			{
				min = j;

				DisplayIntArray(targetArray, targetArraySize, activeElement, selectedElement);
			}
		}

		int temp = targetArray[i];
		targetArray[i] = targetArray[min];
		targetArray[min] = temp;

		selectedElement = i;

		DisplayIntArray(targetArray, targetArraySize, activeElement, selectedElement);

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

		DisplayIntArray(targetArray, targetArraySize, activeElement);

		sleep_for(milliseconds(sleepTime));

		while (j >= 0 && targetArray[j] > temp)
		{
			activeElement = j + 1;
			selectedElement = j;

			DisplayIntArray(targetArray, targetArraySize, activeElement, selectedElement);

			sleep_for(milliseconds(sleepTime));

			targetArray[j + 1] = targetArray[j];
			targetArray[j] = temp;

			activeElement = j;
			selectedElement = j + 1;

			DisplayIntArray(targetArray, targetArraySize, activeElement, selectedElement);

			sleep_for(milliseconds(sleepTime));

			j--;
		}
	}
}