#include <iostream>
#include <vector>
#include <algorithm> // For std::sort, std::find, std::reverse

using namespace std;

//? VECTORS (PART 2: MODIFIERS, ALGORITHMS & ITERATORS)
//* Common vector manipulation functions, iterator navigation, and algorithmic operations.

int main()
{
	cout << "===========================================\n";
	cout << "    02. C++ VECTORS: OPERATIONS & MODS     \n";
	cout << "===========================================\n\n";

	vector<int> numbers = {10, 20, 30, 40, 50};

	//? 1. PUSH_BACK VS EMPLACE_BACK
	//* - push_back(val)   : Copies or moves an existing object to the end of the vector.
	//* - emplace_back(...) : Constructs the element IN-PLACE directly in the vector's memory (more efficient).
	numbers.push_back(60);
	numbers.emplace_back(70);

	cout << "After push_back & emplace_back: ";
	for (int n : numbers) cout << n << " ";
	cout << "\n";

	//? 2. POP_BACK
	//* Removes the last element from the vector (does not return the value).
	numbers.pop_back(); // Removes 70
	cout << "After pop_back():               ";
	for (int n : numbers) cout << n << " ";
	cout << "\n";

	//? 3. INSERTING ELEMENTS (.insert)
	//* Takes an iterator position and element value.
	//* Note: Inserting in the middle or beginning shifts elements to the right (O(n) time).
	numbers.insert(numbers.begin(), 5);           // Insert at beginning
	numbers.insert(numbers.begin() + 3, 25);      // Insert 25 at index 3

	cout << "After insertions:               ";
	for (int n : numbers) cout << n << " ";
	cout << "\n";

	//? 4. ERASING ELEMENTS (.erase)
	//* Can erase single element or a range [first, last).
	numbers.erase(numbers.begin());               // Erase first element (5)
	numbers.erase(numbers.begin() + 2);           // Erase element at index 2 (25)

	cout << "After erase:                    ";
	for (int n : numbers) cout << n << " ";
	cout << "\n";

	//? 5. ITERATORS (begin, end, rbegin, rend)
	//* Iterators act like smart pointers for navigating containers.
	cout << "\n--- Iterators ---\n";
	cout << "Forward with iterators:  ";
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "\n";

	cout << "Reverse with rbegin/rend: ";
	for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << "\n";

	//? 6. USING <algorithm> WITH VECTORS
	vector<int> scores = {85, 42, 99, 12, 73, 60};

	// Sorting in ascending order
	sort(scores.begin(), scores.end());
	cout << "\nSorted scores:            ";
	for (int s : scores) cout << s << " ";
	cout << "\n";

	// Reversing elements
	reverse(scores.begin(), scores.end());
	cout << "Reversed scores:          ";
	for (int s : scores) cout << s << " ";
	cout << "\n";

	// Searching using std::find
	auto it = find(scores.begin(), scores.end(), 73);
	if (it != scores.end())
	{
		cout << "Found score 73 at index:  " << distance(scores.begin(), it) << "\n";
	}
	else
	{
		cout << "Score 73 not found.\n";
	}

	//? 7. CLEARING
	//* .clear() removes all elements (size becomes 0, capacity remains unchanged)
	scores.clear();
	cout << "\nAfter scores.clear() -> Size: " << scores.size() 
	     << ", Capacity: " << scores.capacity() << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a vector of strings representing a student roll call list.
 * 2. Add 4 students using emplace_back.
 * 3. Insert a late student at the 2nd position.
 * 4. Remove a student who dropped out using .erase().
 * 5. Sort the list alphabetically and print in reverse order.
 */

