#include <iostream>
#include <vector>
#include <ranges>
#include <string>

using namespace std;

//? MODERN C++20 / C++23 (PART 2: RANGES & VIEWS)
//* The Ranges library (<ranges>) revolutionizes how we process sequences in C++.
//*
//* Why Ranges & Views?
//* 1. Composability: Combine transformations cleanly using the pipe operator `|`.
//* 2. Lazy Evaluation: Views do NOT copy data into temporary containers;
//*    elements are transformed on-the-fly only when requested during iteration!
//* 3. Cleanliness: No more clunky `begin()` and `end()` pairs everywhere.
//* 4. C++23 additions: std::views::chunk, std::views::slide, std::views::zip, std::views::join_with

int main()
{
	cout << "====================================================\n";
	cout << " 02. MODERN C++: RANGES & VIEWS PIPELINE            \n";
	cout << "====================================================\n\n";

	vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	//? 1. BASIC PIPELINE: FILTER & TRANSFORM
	//* Filter only even numbers, square them, and take the first 3 results.
	cout << "--- 1. Pipe Composition: Even Numbers Squared (Take 3) ---\n";
	auto pipeline = numbers 
		| views::filter([](int n) { return n % 2 == 0; })       // Keep evens
		| views::transform([](int n) { return n * n; })          // Square them
		| views::take(3);                                         // Take only first 3

	for (int val : pipeline)
	{
		cout << val << " "; // Output: 4, 16, 36
	}
	cout << "\n\n";

	//? 2. REVERSING & DROPPING
	cout << "--- 2. Reverse & Drop Views ---\n";
	auto revView = numbers 
		| views::reverse 
		| views::drop(4); // Drop the first 4 from the reversed sequence

	for (int val : revView)
	{
		cout << val << " ";
	}
	cout << "\n\n";

	//? 3. C++23 VIEW: std::views::chunk (Splitting a range into chunks of size N)
	cout << "--- 3. C++23 std::views::chunk (Batching by 3) ---\n";
	auto chunks = numbers | views::chunk(3);

	int batchNum = 1;
	for (auto batch : chunks)
	{
		cout << "Batch " << batchNum++ << ": [ ";
		for (int item : batch)
		{
			cout << item << " ";
		}
		cout << "]\n";
	}

	//? 4. C++23 VIEW: std::views::slide (Sliding Window of size N)
	cout << "\n--- 4. C++23 std::views::slide (Window of 3) ---\n";
	vector<int> data = {10, 20, 30, 40, 50};
	auto window = data | views::slide(3);

	for (auto triplet : window)
	{
		cout << "Window: ( ";
		for (int x : triplet) cout << x << " ";
		cout << ")\n";
	}

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a vector of words: {"apple", "banana", "kiwi", "strawberry", "pear", "orange"}.
 * 2. Use a range pipeline to:
 *    - Filter words with length > 4
 *    - Reverse the remaining sequence
 *    - Take the first 2 words
 * 3. Print the results.
 */

