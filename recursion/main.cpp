#include <iostream>
using namespace std;

void walk(int steps);
int factorial(int num);

int main()
{
	//? Recursion is a programming technique where a function invokes itself from within break a complex concept into a repeatable single step

	// (iterative vs recursive)

	// advatages = less code & is cleaner, useful for sorting & searching algorithms

	// disadvantages = users more memory & slower
	// walk(10);

	cout << factorial(10);

	return 0;
}

void walk(int steps)
{
	//? Iterative approach
	// for(int i = 1; i <= steps; i++){
	// 	cout << "You take a step" << endl;
	// }

	//? Recursive approach
	if (steps > 0)
	{
		cout << steps << " You take a step step" << endl;
		walk(steps - 1);
	}
}

int factorial(int num)
{
	//? Iterative approach
	// int result = 1;
	// for(int i = 1; i <= num; i++){
	// 	result = result * i;
	// }

	// return result;

	//? Recursive approach
	if (num > 1)
	{
		return num * factorial(num - 1);
	}
	else
	{
		return 1;
	}
}