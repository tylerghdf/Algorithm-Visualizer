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


//@brief Displays an integer array as a bar chart scaled to the highest value in console.
//
//@param targetArray: The array you want to display.
//@param targetArraySize: The size of the array you are trying to display.
//@param activeElements: The elements currently being viewed at the current moment.
//@param selectedElements: The elements that are being changed/moved at the current moment.
void DisplayIntArray(int targetArray[], int targetArraySize, int activeElements[2], int selectedElements[2])
{
	const string RED = "\033[31m";
	const string YELLOW = "\033[33m";
	const string GREEN = "\033[32m";
	const string WHITE = "\033[37m";

	const int height = 10;
	float max = targetArray[0];


	for (int i = 0; i < targetArraySize; i++)
	{
		if (targetArray[i] > max)
		{
			max = targetArray[i];
		}
	}

	system("cls");

	// displays the bar chart scaled to the highest value
	for (int i = height; i > 0; i--)
	{
		for (int j = 0; j < targetArraySize; j++)
		{
			if (round(targetArray[j] / max * height) >= i)
			{
				if (IntInArray(selectedElements, 2, j))
				{
					cout << RED << "|" << WHITE;
				}
				else if (IntInArray(activeElements, 2 , j))
				{
					cout << YELLOW << "|" << WHITE;
				} 
				else
				{
					cout << "|";
				}
			}
			else
			{
				cout << " ";
			}
		}

		cout << "\n";
	}
}

//@brief Simple function for displaying an integer array in console.
//
//@param targetArray: Integer array to be displayed
//@param targetArraySize: Size of target array being passed
//@param activeElements: Elements indexes that are being interacted with at the moment -- Yellow
//@param selectedElements: Elements indexes that are being moved/changed at the moment -- Red
void sDisplayIntArray(int targetArray[], int targetArraySize, int activeElements[2], int selectedElements[2])
{
	const string RED = "\033[31m";
	const string YELLOW = "\033[33m";
	const string GREEN = "\033[32m";
	const string WHITE = "\033[37m";

	system("cls");

	cout << "[";

	for (int i = 0; i < targetArraySize; i++)
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
		if (i != targetArraySize - 1)
		{
			cout << ",";
		}
	}

	cout << "]";
}