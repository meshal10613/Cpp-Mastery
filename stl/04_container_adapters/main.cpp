#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

//? STL (PART 4: CONTAINER ADAPTERS)
//* Container adapters do NOT implement new data structures from scratch.
//* Instead, they encapsulate an existing container (like deque or vector)
//* to provide a restricted, specialized interface:
//*
//* 1. std::stack<T>          : LIFO (Last-In, First-Out). Push/Pop from top only.
//* 2. std::queue<T>          : FIFO (First-In, First-Out). Push to back, Pop from front.
//* 3. std::priority_queue<T> : Heap data structure. The highest priority item is always at top.

int main()
{
	cout << "====================================================\n";
	cout << " 04. STL CONTAINER ADAPTERS (STACK & QUEUE)         \n";
	cout << "====================================================\n\n";

	//? 1. std::stack (LIFO: Plates in a cafeteria)
	cout << "--- 1. std::stack<string> (LIFO) ---\n";
	stack<string> plates;
	plates.push("Plate 1 (Red)");
	plates.push("Plate 2 (Green)");
	plates.push("Plate 3 (Blue)");

	cout << "Top plate: " << plates.top() << "\n";
	cout << "Popping all plates:\n";
	while (!plates.empty())
	{
		cout << "  Removing: " << plates.top() << "\n";
		plates.pop();
	}

	//? 2. std::queue (FIFO: Bank line)
	cout << "\n--- 2. std::queue<string> (FIFO) ---\n";
	queue<string> bankLine;
	bankLine.push("Customer Alice");
	bankLine.push("Customer Bob");
	bankLine.push("Customer Charlie");

	cout << "First in line: " << bankLine.front() << "\n";
	cout << "Last in line:  " << bankLine.back() << "\n";
	cout << "Serving customers:\n";
	while (!bankLine.empty())
	{
		cout << "  Now serving: " << bankLine.front() << "\n";
		bankLine.pop();
	}

	//? 3. std::priority_queue (Max-Heap by default)
	cout << "\n--- 3. std::priority_queue<int> (Max-Heap) ---\n";
	priority_queue<int> emergencyQueue; // Highest number = highest priority
	emergencyQueue.push(30);
	emergencyQueue.push(100);
	emergencyQueue.push(50);
	emergencyQueue.push(10);

	cout << "Processing emergency cases by priority level:\n";
	while (!emergencyQueue.empty())
	{
		cout << "  Handling priority level: " << emergencyQueue.top() << "\n";
		emergencyQueue.pop();
	}

	// Min-Heap priority queue (lowest number first)
	cout << "\n--- Min-Heap Priority Queue (std::greater) ---\n";
	priority_queue<int, vector<int>, greater<int>> minHeap;
	minHeap.push(45);
	minHeap.push(12);
	minHeap.push(89);

	cout << "Min-heap top (smallest number): " << minHeap.top() << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Balanced Parentheses Checker:
 *    Use a `std::stack<char>` to check if a string of parentheses like "({[]})" is valid.
 * 2. Push opening brackets `(`, `{`, `[` onto the stack.
 * 3. Pop and match when encountering closing brackets `)`, `}`, `]`.
 */

