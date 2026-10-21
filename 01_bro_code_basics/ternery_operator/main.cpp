#include <iostream>
using namespace std;

int main()
{
	//? Ternary operator is a shorthand for if-else statement. It takes three operands and is used to evaluate a condition and return one of two values based on the result of that condition.
	int age = 21;
	string result = (age >= 18) ? "You are an adult." : "You are not an adult.";

	cout << result << endl;

	return 0;
}