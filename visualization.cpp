#include <iostream>
#include "visualization.h"

using namespace std;

//This function is only temporarily here
//@brief Determines if an integer is in a given integer array.
//
//@param targetArray: Integer array that will be searched.
//@param targetArraySize: Size of the given integer array.
//@param targetInt: The integer you are searching the array for.
bool IntInArray(int targetArray[], int targetArraySize, int targetInt)
{
	int nullElement = 0;
	bool inArray = false;

	// Arrays are being declared as nullptr. Makes sure the array isn't just empty.
	if (targetArray == nullptr)
	{
		return false;
	}

	for (int i = 0; i < targetArraySize; i++)
	{
		if (targetArray[i] == targetInt)
		{
			return true;
		}
	}

	return false;
}

//@brief Writes given array to the console using self determined styling.
//
//@param targetArray: Integer array to be displayed
//@param targetArraySize: Size of target array being passed
//@param activeElements: Elements indexes that are being interacted with at the moment -- Yellow
//@param selectedElements: Elements indexes that are being moved/changed at the moment -- Red
void DisplayIntArray(int targetArray[], int targetArraySize, int activeElements[2], int selectedElements[2])
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
		if (IntInArray(selectedElements, 2, i))
		{
			cout << RED << targetArray[i] << WHITE;
		}
		else if (IntInArray(activeElements, 2, i))
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