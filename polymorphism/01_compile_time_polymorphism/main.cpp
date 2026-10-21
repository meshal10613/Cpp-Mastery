#include <iostream>
#include <string>

using namespace std;

//? POLYMORPHISM (PART 1: COMPILE-TIME / STATIC POLYMORPHISM)
//* Polymorphism means "many forms" (Greek: poly = many, morph = form).
//* Compile-Time (Static) Polymorphism is resolved during compilation.
//* The two main forms are:
//* 1. Function Overloading (same function name, different parameter types or count)
//* 2. Operator Overloading (giving custom meaning to C++ operators for user-defined classes)

// Example Class: 2D Point with Operator Overloading
class Point
{
private:
	int x, y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	//? 1. OPERATOR OVERLOADING (+ operator)
	//* Allows us to write: Point p3 = p1 + p2;
	Point operator+(const Point &other) const
	{
		return Point(this->x + other.x, this->y + other.y);
	}

	//? 2. OPERATOR OVERLOADING (== equality comparison)
	//* Allows us to write: if (p1 == p2)
	bool operator==(const Point &other) const
	{
		return (this->x == other.x && this->y == other.y);
	}

	//? 3. STREAM INSERTION OVERLOADING (<< operator)
	//* Declared as a friend function so it has access to private members x and y
	friend ostream &operator<<(ostream &os, const Point &p)
	{
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}
};

// Function Overloading Demonstration
int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

string add(const string &a, const string &b)
{
	return a + " " + b;
}

int main()
{
	cout << "====================================================\n";
	cout << " 01. COMPILE-TIME POLYMORPHISM (OVERLOADING)        \n";
	cout << "====================================================\n\n";

	// 1. Function Overloading in action
	cout << "--- Function Overloading ---\n";
	cout << "add(5, 10):           " << add(5, 10) << "\n";
	cout << "add(2.5, 3.7):        " << add(2.5, 3.7) << "\n";
	cout << "add(\"Hello\", \"Bro\"): " << add("Hello", "Bro") << "\n\n";

	// 2. Operator Overloading in action
	cout << "--- Operator Overloading (+, ==, <<) ---\n";
	Point p1(3, 4);
	Point p2(1, 2);
	Point p3 = p1 + p2; // Calls p1.operator+(p2)

	cout << "p1:       " << p1 << "\n";
	cout << "p2:       " << p2 << "\n";
	cout << "p1 + p2:  " << p3 << "\n";

	if (p1 == p2)
	{
		cout << "p1 and p2 are equal\n";
	}
	else
	{
		cout << "p1 and p2 are NOT equal\n";
	}

	Point p4(3, 4);
	cout << "p1 == p4: " << (p1 == p4 ? "true" : "false") << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a `Complex` number class storing `real` and `imag` numbers.
 * 2. Overload the `+` operator to add two complex numbers: (a + bi) + (c + di) = (a+c) + (b+d)i.
 * 3. Overload the `<<` operator to print complex numbers as `a + bi`.
 */

