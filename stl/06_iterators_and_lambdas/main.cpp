#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

//? STL (PART 6: ITERATORS & LAMBDA EXPRESSIONS)
//* 
//* Iterators:
//* An iterator is an object that points to an element inside a container,
//* abstracting away the container's underlying memory structure.
//*
//* Lambda Expressions (Anonymous Functions):
//* Syntax: [capture_clause](parameters) -> return_type { body }
//* - []      : Empty capture (no external variables accessed)
//* - [&]     : Capture all external variables by reference
//* - [=]     : Capture all external variables by value (copy)
//* - [x, &y] : Capture x by value, y by reference

int main()
{
	cout << "====================================================\n";
	cout << " 06. STL ITERATORS & MODERN LAMBDAS                 \n";
	cout << "====================================================\n\n";

	vector<int> numbers = {10, 20, 30, 40, 50};

	//? 1. ITERATOR UTILITIES
	//* std::advance, std::next, std::prev
	cout << "--- 1. Iterator Navigation ---\n";
	auto it = numbers.begin();
	cout << "Start element:   " << *it << "\n";

	advance(it, 3); // Moves it forward by 3 steps
	cout << "After advance 3: " << *it << "\n";

	auto prevIt = prev(it); // Returns iterator 1 step back without moving `it`
	auto nextIt = next(it); // Returns iterator 1 step forward without moving `it`
	cout << "prev: " << *prevIt << ", next: " << *nextIt << "\n\n";

	//? 2. LAMBDA EXPRESSIONS
	cout << "--- 2. Lambda Expressions ---\n";

	// Simple lambda assigned to variable
	auto greet = [](const string &name) {
		cout << "Hello, " << name << "!\n";
	};
	greet("C++ Developer");

	// Lambda with return type
	auto multiply = [](double a, double b) -> double {
		return a * b;
	};
	cout << "5.5 * 4.0 = " << multiply(5.5, 4.0) << "\n";

	// Lambda capturing external variables
	int threshold = 25;
	auto isAboveThreshold = [threshold](int val) {
		return val > threshold;
	};

	cout << "\nChecking numbers above threshold (" << threshold << "):\n";
	for (int n : numbers)
	{
		if (isAboveThreshold(n))
		{
			cout << "  - " << n << " is above threshold.\n";
		}
	}

	//? 3. LAMBDA WITH STL ALGORITHMS (std::for_each & std::sort)
	cout << "\n--- 3. Using Lambdas with STL Algorithms ---\n";
	vector<string> words = {"banana", "fig", "apple", "date", "strawberry"};

	// Custom sorting by word length using lambda
	sort(words.begin(), words.end(), [](const string &a, const string &b) {
		return a.length() < b.length(); // Shortest word first
	});

	cout << "Sorted by word length: ";
	for (const auto &w : words) cout << w << " ";
	cout << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a vector of products with a name and price struct.
 * 2. Use `std::sort` with a lambda to sort products by price ascending.
 * 3. Use `std::for_each` with a lambda to apply a 10% discount to all products.
 */

