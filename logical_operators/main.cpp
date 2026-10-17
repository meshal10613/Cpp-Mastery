#include <iostream>
using namespace std;

int main()
{
	//? Logical operators are used to combine multiple conditions in decision-making statements. The most common logical operators are AND (&&), OR (||), and NOT (!).
	int temp;
	cout << "Enter the temperature in Celsius: ";
	cin >> temp;

	if (temp > 0 && temp < 30)
	{
		cout << "The weather is pleasant." << endl;
	}
	else if (temp <= 0 || temp >= 30)
	{
		cout << "The weather is extreme." << endl;
	}
	else
	{
		cout << "Invalid temperature input." << endl;
	}

	return 0;
}