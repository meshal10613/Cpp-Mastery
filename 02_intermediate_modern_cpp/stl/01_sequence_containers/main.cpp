#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>

using namespace std;

//? STL (PART 1: SEQUENCE CONTAINERS)
//* Sequence containers store elements in a linear, sequential order.
//* 
//* 1. std::vector<T>       : Contiguous dynamic array on heap. Fast random access O(1), fast append O(1).
//* 2. std::deque<T>        : Double-ended queue. Fast insert/delete at BOTH front and back O(1).
//* 3. std::list<T>         : Doubly linked list. Fast insert/delete anywhere O(1) once iterator is found. No random access.
//* 4. std::forward_list<T> : Singly linked list (saves memory, forward traversal only).
//* 5. std::array<T, N>     : Fixed-size array stored on the stack. Zero overhead, knows its own size.

int main()
{
	cout << "====================================================\n";
	cout << " 01. STL SEQUENCE CONTAINERS                        \n";
	cout << "====================================================\n\n";

	//? 1. std::array<T, N> (Stack-allocated, type-safe array)
	cout << "--- 1. std::array<int, 4> ---\n";
	array<int, 4> arr = {1, 2, 3, 4};
	cout << "Array size: " << arr.size() << ", front: " << arr.front() << ", back: " << arr.back() << "\n";

	//? 2. std::deque<T> (Double Ended Queue)
	cout << "\n--- 2. std::deque<string> ---\n";
	deque<string> line;
	line.push_back("Bob");
	line.push_back("Charlie");
	line.push_front("Alice"); // Efficient front insertion!

	cout << "Deque contents: ";
	for (const auto &p : line) cout << p << " ";
	cout << "\n";

	line.pop_front(); // Alice leaves
	cout << "After pop_front(): ";
	for (const auto &p : line) cout << p << " ";
	cout << "\n";

	//? 3. std::list<T> (Doubly Linked List)
	cout << "\n--- 3. std::list<int> ---\n";
	list<int> linkedList = {10, 20, 30, 40};
	linkedList.push_front(5);
	linkedList.push_back(50);

	// Inserting 25 before 30 (finding iterator first)
	for (auto it = linkedList.begin(); it != linkedList.end(); ++it)
	{
		if (*it == 30)
		{
			linkedList.insert(it, 25);
			break;
		}
	}

	cout << "List after insertions: ";
	for (int n : linkedList) cout << n << " ";
	cout << "\n";

	//? SUMMARY TABLE OF SEQUENCE CONTAINERS:
	//+--------------------+----------------+-----------------+-------------------+
	//| Container          | Random Access  | Insert at Front | Insert at Back    |
	//+--------------------+----------------+-----------------+-------------------+
	//| std::array         | O(1)           | N/A (Fixed)     | N/A (Fixed)       |
	//| std::vector        | O(1)           | O(n)            | O(1) amortized    |
	//| std::deque         | O(1)           | O(1)            | O(1)              |
	//| std::list          | O(n)           | O(1)            | O(1)              |
	//+--------------------+----------------+-----------------+-------------------+

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a `std::deque` representing a browser's back/forward history.
 * 2. Push URLs to the back as you browse new pages.
 * 3. Pop URLs from the back when clicking the "Back" button.
 */

