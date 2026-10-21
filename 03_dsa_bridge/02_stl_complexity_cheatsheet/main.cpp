#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

//? DSA BRIDGE (02. STL COMPLEXITY & CACHE LOCALITY CHEAT SHEET)
//* Choosing the right STL container directly determines whether your algorithm passes or fails.
//*
//* Quick Lookup & Insertion Cheat Sheet:
//* +----------------------+---------------+---------------+-------------------+
//* | Container            | Lookup        | Insertion     | Underlying Tech   |
//* +----------------------+---------------+---------------+-------------------+
//* | std::vector          | O(1) by index | O(1) back     | Contiguous Array  |
//* | std::list            | O(N)          | O(1) (known)  | Doubly Linked List|
//* | std::map             | O(log N)      | O(log N)      | Red-Black Tree    |
//* | std::unordered_map   | O(1) average  | O(1) average  | Hash Table        |
//* +----------------------+---------------+---------------+-------------------+
//*
//* Why is std::vector almost ALWAYS faster than std::list?
//* -> CACHE LOCALITY: Array elements are stored right next to each other in RAM.
//*    CPUs pull cache lines (64 bytes) into L1/L2 cache, making vector traversal lightning fast!

int main()
{
	cout << "====================================================\n";
	cout << " 02. DSA BRIDGE: STL BENCHMARKS & CACHE LOCALITY    \n";
	cout << "====================================================\n\n";

	int elements = 200000;
	cout << "Benchmarking with " << elements << " elements...\n\n";

	//? 1. Vector Traversal (Contiguous memory in CPU cache)
	vector<int> vec(elements, 1);
	auto t1 = high_resolution_clock::now();
	long long sumVec = 0;
	for (int n : vec) sumVec += n;
	auto t2 = high_resolution_clock::now();
	cout << "Vector Traversal:         " 
	     << duration_cast<microseconds>(t2 - t1).count() << " microseconds (Cache Friendly!)\n";

	//? 2. List Traversal (Scattered heap memory nodes)
	list<int> lst(elements, 1);
	t1 = high_resolution_clock::now();
	long long sumList = 0;
	for (int n : lst) sumList += n;
	t2 = high_resolution_clock::now();
	cout << "List Traversal:           " 
	     << duration_cast<microseconds>(t2 - t1).count() << " microseconds (Cache Misses!)\n\n";

	//? 3. std::map vs std::unordered_map Lookup
	map<int, int> orderedMap;
	unordered_map<int, int> hashMap;

	for (int i = 0; i < elements; i++)
	{
		orderedMap[i] = i;
		hashMap[i] = i;
	}

	t1 = high_resolution_clock::now();
	volatile int val1 = orderedMap[elements / 2];
	t2 = high_resolution_clock::now();
	cout << "std::map Search O(log N): " 
	     << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds\n";

	t1 = high_resolution_clock::now();
	volatile int val2 = hashMap[elements / 2];
	t2 = high_resolution_clock::now();
	cout << "std::unordered_map O(1):  " 
	     << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds\n";

	return 0;
}

