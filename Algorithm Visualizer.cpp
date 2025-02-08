#include <iostream>
#include "intarrayalgorithm.h"

int main()
{
	int numbers[] = {9,2,1,5,6,4,7,8,8,2};

	InsertionSort(numbers, sizeof(numbers) / sizeof(numbers[0]));

	BubbleSort(numbers, sizeof(numbers) / sizeof(numbers[0]));

	SelectionSort(numbers, sizeof(numbers) / sizeof(numbers[0]));
}