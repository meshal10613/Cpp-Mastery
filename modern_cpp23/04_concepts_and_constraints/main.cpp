#include <iostream>
#include <concepts>
#include <string>
#include <vector>

using namespace std;

//? MODERN C++20 / C++23 (PART 4: CONCEPTS & CONSTRAINTS)
//* Before Concepts, passing the wrong type to a C++ template generated
//* hundreds of lines of cryptic compiler error messages (SFINAE hell).
//*
//* Concepts (<concepts>) allow you to define COMPILE-TIME CONSTRAINTS on template arguments:
//* 1. Readable compiler errors: Compiler directly tells you "type X does not satisfy concept Y".
//* 2. Self-documenting code: Function signatures state exactly what types they accept.
//* 3. Function overloading based on constraints!

//? 1. DEFINING A CUSTOM CONCEPT
//* Concept requiring type T to support addition and have numeric traits
template <typename T>
concept Numeric = is_arithmetic_v<T>;

// Concept requiring type T to be printable with std::cout
template <typename T>
concept Printable = requires(T a) {
	cout << a; // Validates that expression is well-formed
};

//? 2. APPLYING CONSTRAINTS
// Syntax Style A: Using concept directly as the type parameter
template <Numeric T>
T calculateAverage(T a, T b)
{
	return (a + b) / 2;
}

// Syntax Style B: Using the `requires` clause
template <typename T>
requires Printable<T>
void printItem(const T &item)
{
	cout << "Item: " << item << "\n";
}

// Syntax Style C: Terse Syntax (auto with concept in parameter list)
void displayNumeric(Numeric auto val)
{
	cout << "Numeric Value: " << val << "\n";
}

int main()
{
	cout << "====================================================\n";
	cout << " 04. CONCEPTS & COMPILE-TIME CONSTRAINTS            \n";
	cout << "====================================================\n\n";

	// 1. Constrained functions with valid numeric types
	cout << "Average of ints (10, 20):       " << calculateAverage(10, 20) << "\n";
	cout << "Average of doubles (3.5, 7.5):  " << calculateAverage(3.5, 7.5) << "\n";

	// calculateAverage("Hello", "World"); 
	// ❌ If uncommented, produces clean error: "template constraint failure: string is not Numeric!"

	// 2. Terse syntax in action
	displayNumeric(42);
	displayNumeric(99.99f);

	// 3. Printable concept
	printItem(1337);
	printItem(string("Modern C++ Concepts are Awesome!"));

	// 4. Standard Library Concepts (<concepts>):
	//* - std::integral<T>
	//* - std::floating_point<T>
	//* - std::same_as<T, U>
	//* - std::convertible_to<From, To>
	//* - std::equality_comparable<T>

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Define a concept `Addable` that requires `a + b` to be valid for type `T`.
 * 2. Create a constrained template function `T sum(T a, T b)`.
 * 3. Test that `sum(10, 20)` and `sum(string("A"), string("B"))` compile,
 *    while a non-addable struct triggers a clean compiler error.
 */

