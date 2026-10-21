#include <iostream>
#include <expected>
#include <optional>
#include <string>

using namespace std;

//? MODERN C++23 (PART 3: std::expected & MONADIC std::optional)
//* Exception Handling (try/catch) has overhead and can disrupt control flow.
//* Returning error codes or magic numbers (-1, null) is error-prone.
//* 
//* C++23 introduces `std::expected<T, E>` (<expected>):
//* - Represents EITHER a valid value of type T, OR an unexpected error of type E!
//* - Eliminates exceptions for expected business errors.
//* - Explicit, type-safe, and zero-cost abstraction.
//*
//* C++23 Monadic operations on `std::optional`:
//* - `.and_then()` : Chain functions that return an optional.
//* - `.transform()`: Transform the inner value if present.
//* - `.or_else()`  : Provide fallback handling if empty.

// Error enum for domain-specific errors
enum class MathError
{
	DivisionByZero,
	NegativeSquareRoot
};

string errorToString(MathError err)
{
	switch (err)
	{
		case MathError::DivisionByZero: return "Error: Cannot divide by zero!";
		case MathError::NegativeSquareRoot: return "Error: Cannot compute square root of negative number!";
		default: return "Unknown error";
	}
}

// Function returning std::expected<double, MathError>
expected<double, MathError> safeDivide(double numerator, double denominator)
{
	if (denominator == 0.0)
	{
		return unexpected(MathError::DivisionByZero);
	}
	return numerator / denominator;
}

// Function using std::optional with C++23 Monadic operations
optional<string> findUserEmail(int userId)
{
	if (userId == 101) return "alice@example.com";
	if (userId == 102) return "bob@domain.org";
	return nullopt; // Not found
}

int main()
{
	cout << "====================================================\n";
	cout << " 03. MODERN C++23: std::expected & MONADIC OPTIONAL \n";
	cout << "====================================================\n\n";

	//? 1. std::expected SUCCESS CASE
	cout << "--- 1. std::expected Handling ---\n";
	auto result1 = safeDivide(100.0, 4.0);

	if (result1.has_value()) // Or simply: if (result1)
	{
		cout << "Success! 100 / 4 = " << result1.value() << " (or *result1 = " << *result1 << ")\n";
	}

	//? 2. std::expected FAILURE CASE
	auto result2 = safeDivide(50.0, 0.0);

	if (!result2)
	{
		cout << "Operation failed! " << errorToString(result2.error()) << "\n";
		// Using .value_or() to provide fallback default
		cout << "Fallback value_or(0.0): " << result2.value_or(0.0) << "\n\n";
	}

	//? 3. C++23 MONADIC OPERATIONS ON std::optional
	cout << "--- 2. Monadic Optional Chaining (.transform, .and_then) ---\n";
	
	// Convert email to uppercase domain if user exists
	auto extractDomain = [](int id) {
		return findUserEmail(id)
			.transform([](const string &email) {
				// Extract part after '@'
				size_t atPos = email.find('@');
				return (atPos != string::npos) ? email.substr(atPos + 1) : email;
			})
			.value_or("Domain Unavailable");
	};

	cout << "User 101 domain: " << extractDomain(101) << "\n";
	cout << "User 999 domain: " << extractDomain(999) << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Write a function `safeParseInt(const string &str)` returning `std::expected<int, string>`.
 * 2. If the string contains non-digit characters, return an unexpected error message.
 * 3. Otherwise, convert and return the integer value.
 * 4. Test with "1234" and "12a45".
 */

