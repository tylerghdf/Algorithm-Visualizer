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

	int activeElements[2];
	int selectedElements[2];

	for (int i = 0; i < targetArraySize - 1; i++)
	{
		for (int j = 0; j < targetArraySize - i - 2; j++)
		{
			activeElements[0] = j;

			DisplayIntArray(targetArray, targetArraySize, activeElements);

			sleep_for(milliseconds(sleepTime));

			if (targetArray[j] > targetArray[j + 1])
			{
				selectedElements[0] = j + 1;

				DisplayIntArray(targetArray, targetArraySize, activeElements, selectedElements);

				sleep_for(milliseconds(sleepTime));

				int temp = targetArray[j];
				targetArray[j] = targetArray[j + 1];
				targetArray[j + 1] = temp;
			}

			activeElements[0] = j + 1;
			selectedElements[0] = j;

			DisplayIntArray(targetArray, targetArraySize, activeElements, selectedElements);

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

	int activeElements[2];
	int selectedElements[2];

	for (int i = 0; i < targetArraySize; i++)
	{
		int min = i;

		for (int j = 0 + i; j < targetArraySize; j++)
		{
			activeElements[0] = j;
			selectedElements[0] = min;

			DisplayIntArray(targetArray, targetArraySize, activeElements, selectedElements);

			sleep_for(milliseconds(sleepTime));

			if (targetArray[j] < targetArray[min])
			{
				min = j;

				DisplayIntArray(targetArray, targetArraySize, activeElements, selectedElements);
			}
		}

		int temp = targetArray[i];
		targetArray[i] = targetArray[min];
		targetArray[min] = temp;

		selectedElements[0] = i;

		DisplayIntArray(targetArray, targetArraySize, activeElements, selectedElements);

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

	int activeElements[2];
	int selectedElements[2];

	for (int i = 1; i < targetArraySize; i++)
	{
		int temp = targetArray[i];
		int j = i - 1;

		activeElements[0] = i;

		DisplayIntArray(targetArray, targetArraySize, activeElements);

		sleep_for(milliseconds(sleepTime));

		while (j >= 0 && targetArray[j] > temp)
		{
			activeElements[0] = j + 1;
			selectedElements[0] = j;

			DisplayIntArray(targetArray, targetArraySize, activeElements, selectedElements);

			sleep_for(milliseconds(sleepTime));

			targetArray[j + 1] = targetArray[j];
			targetArray[j] = temp;

			activeElements[0] = j;
			selectedElements[0] = j + 1;

			DisplayIntArray(targetArray, targetArraySize, activeElements, selectedElements);

			sleep_for(milliseconds(sleepTime));

			j--;
		}
	}
}