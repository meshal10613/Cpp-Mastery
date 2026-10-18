#include <iostream>
using namespace std;

int searchArray(int array[], int size, int element);

int main()
{
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int index, element;

	cout << "Enter element to search for: ";
	cin >> element;

	index = searchArray(numbers, size, element);
	if (index == -1)
	{
		cout << element << " is not in the array";
	}
	else
	{
		cout << "The element is in " << index << " position";
	}

	return 0;
}

int searchArray(int array[], int size, int element)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == element)
		{
			return i;
		}
	}

	return -1;
}