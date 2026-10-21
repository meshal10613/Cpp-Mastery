#include <iostream>
#include <string>
#include <vector>

using namespace std;

//? MODERN C++23 (PART 5: DEDUCING THIS / EXPLICIT OBJECT PARAMETERS)
//* In traditional C++, the current object is implicitly passed as the `this` pointer.
//* C++23 introduces "Deducing this" (P0847R7):
//* You can now pass the object explicitly as the first parameter of a member function or lambda!
//*
//* Why is this a game changer?
//* 1. Elegant Recursive Lambdas: Lambdas can easily call themselves without std::function overhead!
//* 2. Eliminates const / non-const code duplication: One template method handles both!
//* 3. CRTP (Curiously Recurring Template Pattern) made simple without complicated inheritance.

//? 1. AVOIDING CONST/NON-CONST DUPLICATION USING `this auto&&`
class SafeBuffer
{
private:
	vector<int> data = {10, 20, 30, 40, 50};

public:
	// In C++20 and older, you had to write TWO functions:
	// int& at(size_t i) { return data[i]; }
	// const int& at(size_t i) const { return data[i]; }
	//
	// In C++23: ONE function deduces both constness and reference category!
	template <typename Self>
	auto &at(this Self &&self, size_t index)
	{
		return self.data.at(index);
	}
};

//? 2. METHOD CHAINING / FLUENT API
class QueryBuilder
{
private:
	string query;

public:
	// Deducing this preserves the derived type in method chaining!
	template <typename Self>
	Self &&select(this Self &&self, const string &cols)
	{
		self.query += "SELECT " + cols + " ";
		return forward<Self>(self);
	}

	template <typename Self>
	Self &&from(this Self &&self, const string &table)
	{
		self.query += "FROM " + table + " ";
		return forward<Self>(self);
	}

	void print() const
	{
		cout << "Generated SQL: " << query << "\n";
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " 05. MODERN C++23: DEDUCING THIS                    \n";
	cout << "====================================================\n\n";

	//? 1. RECURSIVE LAMBDAS (C++23)
	//* Notice: `this auto self` gives the lambda a self-reference!
	cout << "--- 1. Recursive Lambda (Factorial) ---\n";
	auto factorial = [](this auto self, int n) -> long long {
		if (n <= 1) return 1;
		return n * self(n - 1);
	};

	cout << "Factorial(5) = " << factorial(5) << "\n";
	cout << "Factorial(7) = " << factorial(7) << "\n\n";

	// Recursive Fibonacci
	cout << "--- 2. Recursive Lambda (Fibonacci) ---\n";
	auto fibonacci = [](this auto self, int n) -> int {
		if (n <= 0) return 0;
		if (n == 1) return 1;
		return self(n - 1) + self(n - 2);
	};

	cout << "Fibonacci(8) = " << fibonacci(8) << "\n\n";

	//? 2. DEDUCING THIS FOR CONST & MUTABLE ACCESS
	cout << "--- 3. Const & Mutable Member Access ---\n";
	SafeBuffer mutableBuffer;
	mutableBuffer.at(0) = 999; // Mutates non-const buffer!
	cout << "Modified index 0: " << mutableBuffer.at(0) << "\n";

	const SafeBuffer constBuffer;
	cout << "Read-only index 1: " << constBuffer.at(1) << "\n\n";

	//? 3. FLUENT BUILDER CHAINING
	cout << "--- 4. Fluent Method Chaining ---\n";
	QueryBuilder qb;
	qb.select("id, username, email").from("users");
	qb.print();

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Write a recursive lambda using `this auto self` to calculate the GCD (Greatest Common Divisor)
 *    of two integers using Euclid's algorithm: gcd(a, b) = b == 0 ? a : self(b, a % b).
 * 2. Test it with numbers 48 and 18.
 */

