#include <iostream>
#include "visualization.h"

using namespace std;

//@brief Writes given array to the console using self determined styling.
//
//@param targetArray: Integer array to be displayed
//@param targetArraySize: Size of target array being passed
//@param activeElements: Elements indexes that are being interacted with at the moment -- Yellow
//@param selectedElements: Elements indexes that are being moved/changed at the moment -- Red
void DisplayIntArray(int targetArray[], int targetArraySize, int activeElement, int selectedElement)
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