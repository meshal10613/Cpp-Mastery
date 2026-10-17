#include <iostream>
using namespace std;

int main()
{
	char op;
	double num1, num2;

	cout << "************** Simple Calculator **************" << endl;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter operator (+, -, *, /): ";
	cin >> op;
	cout << "Enter second number: ";
	cin >> num2;

	switch (op)
	{
	case '+':
		cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
		break;
	case '*':
		cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
		break;
	case '/':
		if (num2 == 0)
		{
			cout << "Error: Division by zero!" << endl;
		}
		else
		{
			cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
		}
		break;
	default:
		cout << "Invalid operator!" << endl;
	}
	cout << "***********************************************" << endl;

	return 0;
}