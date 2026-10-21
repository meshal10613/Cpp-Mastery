#include <iostream>
using namespace std;

int main()
{
	//? if statements are used to make decisions in a program based on certain conditions. They allow the program to execute different blocks of code depending on whether a condition is true or false.

	int age;

	cout << "Enter your age: ";
	cin >> age;

	if (age >= 18 && age <= 65)
	{
		cout << "You are an adult." << endl;
	}
	else if (age > 65)
	{
		cout << "You are a senior citizen." << endl;
	}
	else if (age < 0)
	{
		cout << "Invalid age." << endl;
	}
	else
	{
		cout << "You are a minor." << endl;
	}

	return 0;
}