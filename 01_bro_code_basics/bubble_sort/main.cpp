#include <iostream>
using namespace std;

int main()
{
	int array[] = {5, 3, 1, 4, 2};
	int size = sizeof(array) / sizeof(int);
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (int a : array)
	{
		cout << a << endl;
	}

	return 0;
}