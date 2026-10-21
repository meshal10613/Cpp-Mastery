#include<iostream>
using namespace std;

int main() {
	//? Type conversion in C++ is the process of converting a variable from one data type to another. There are two types of type conversion: implicit and explicit.
	//* Implicit type conversion (also known as type casting) is automatically performed by the compiler when a value of one data type is assigned to a variable of another data type. For example, when an integer is assigned to a float variable, the integer is automatically converted to a float.
	//* Explicit type conversion (also known as type casting) is performed by the programmer using a cast operator. For example, when a float value is assigned to an integer variable, the programmer can use a cast operator to explicitly convert the float to an integer.


	// double x = (int)3.1416;

	// cout << x;

	int correct = 8;
	int questions = 10;
	double score = (double)correct / questions * 100;
	cout << score;

	return 0;
}