#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

//? DSA BRIDGE (04. MEMORY OVERHEAD: PASS-BY-VALUE VS PASS-BY-REFERENCE)
//* The #1 silent bug in Competitive Programming & LeetCode:
//* Passing a large std::vector or std::string by VALUE copies all its heap buffers!
//* - Time Complexity becomes O(N) per function call instead of O(1).
//* - In recursive algorithms (DFS, backtracking), this causes TLE (Time Limit Exceeded)
//*   and MLE (Memory Limit Exceeded).
//*
//* ALWAYS PASS BY CONST REFERENCE (`const vector<int>&`) when read-only!

// SLOW: Copies the entire vector each time!
long long passByValue(vector<int> vec)
{
	return vec.empty() ? 0 : vec[0];
}

// FAST: Zero copies! Directly aliases the original memory.
long long passByConstRef(const vector<int> &vec)
{
	return vec.empty() ? 0 : vec[0];
}

int main()
{
	cout << "====================================================\n";
	cout << " 04. DSA BRIDGE: PASS-BY-VALUE VS PASS-BY-REFERENCE \n";
	cout << "====================================================\n\n";

	int N = 5000000; // 5 Million integers (~20 MB in RAM)
	vector<int> largeArray(N, 42);

	int iterations = 100;
	cout << "Testing " << iterations << " calls on a 20 MB vector...\n\n";

	// 1. Pass by Value (Copies 20 MB x 100 = 2 GB of useless allocations!)
	auto t1 = high_resolution_clock::now();
	for (int i = 0; i < iterations; i++)
	{
		volatile long long val = passByValue(largeArray);
	}
	auto t2 = high_resolution_clock::now();
	cout << "Pass-by-Value:      " 
	     << duration_cast<milliseconds>(t2 - t1).count() << " milliseconds (HUGE overhead!)\n";

	// 2. Pass by Const Reference (Zero copies!)
	t1 = high_resolution_clock::now();
	for (int i = 0; i < iterations; i++)
	{
		volatile long long val = passByConstRef(largeArray);
	}
	t2 = high_resolution_clock::now();
	cout << "Pass-by-Const-Ref:  " 
	     << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds (Instantaneous!)\n";

	return 0;
}

