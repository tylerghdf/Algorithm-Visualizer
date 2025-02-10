#include <iostream>
#include "intarrayalgorithm.h"
#include "visualization.h"

int main()
{
	int numbers[] = {5,3,1,6,2,8,1,9,11};

	BubbleSort(numbers, sizeof(numbers) / sizeof(numbers[0]));
}