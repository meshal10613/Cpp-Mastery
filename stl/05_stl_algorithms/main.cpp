#include <iostream>
#include <vector>
#include <algorithm> // sort, find, count, reverse, binary_search, replace, any_of
#include <numeric>   // accumulate, reduce

using namespace std;

//? STL (PART 5: ALGORITHMS)
//* STL algorithms operate on containers via ITERATORS [first, last).
//* They eliminate the need to write raw loops for common operations.
//*
//* Categories:
//* 1. Non-modifying : find, count, all_of, any_of, none_of
//* 2. Modifying     : copy, replace, fill, transform, reverse
//* 3. Sorting & Ops : sort, stable_sort, binary_search, min_element, max_element
//* 4. Numeric       : accumulate, iota, reduce

int main()
{
	cout << "====================================================\n";
	cout << " 05. STL ALGORITHMS (<algorithm> & <numeric>)       \n";
	cout << "====================================================\n\n";

	vector<int> numbers = {14, 3, 27, 9, 42, 3, 88, 15};

	//? 1. Non-Modifying Algorithms
	cout << "--- 1. Non-Modifying Algorithms ---\n";
	// Count occurrences of 3
	int count3 = count(numbers.begin(), numbers.end(), 3);
	cout << "Occurrences of 3: " << count3 << "\n";

	// Check if any element is negative
	bool hasNegative = any_of(numbers.begin(), numbers.end(), [](int x) { return x < 0; });
	cout << "Contains negative number: " << (hasNegative ? "Yes" : "No") << "\n";

	//? 2. Min & Max Elements
	auto minIt = min_element(numbers.begin(), numbers.end());
	auto maxIt = max_element(numbers.begin(), numbers.end());
	cout << "Smallest element: " << *minIt << " at index " << distance(numbers.begin(), minIt) << "\n";
	cout << "Largest element:  " << *maxIt << " at index " << distance(numbers.begin(), maxIt) << "\n";

	//? 3. Sorting & Binary Search
	cout << "\n--- 2. Sorting & Binary Search ---\n";
	sort(numbers.begin(), numbers.end()); // O(n log n) Introsort
	cout << "Sorted numbers: ";
	for (int n : numbers) cout << n << " ";
	cout << "\n";

	// Binary search requires the container to be sorted first!
	bool found42 = binary_search(numbers.begin(), numbers.end(), 42);
	cout << "Is 42 in the collection? " << (found42 ? "Yes" : "No") << "\n";

	//? 4. Transforming Elements (std::transform)
	cout << "\n--- 3. std::transform (Double each value) ---\n";
	vector<int> doubled(numbers.size());
	transform(numbers.begin(), numbers.end(), doubled.begin(), [](int n) {
		return n * 2;
	});

	cout << "Doubled: ";
	for (int n : doubled) cout << n << " ";
	cout << "\n";

	//? 5. Numeric: std::accumulate (Summing up)
	cout << "\n--- 4. std::accumulate (Sum) ---\n";
	int totalSum = accumulate(numbers.begin(), numbers.end(), 0);
	cout << "Total sum of numbers: " << totalSum << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a vector of test scores: {75, 88, 92, 60, 55, 99, 81}.
 * 2. Count how many scores are passing (>= 70) using `std::count_if`.
 * 3. Calculate the average score using `std::accumulate`.
 * 4. Sort the scores in descending order using `std::sort` with `std::greater<int>()`.
 */

