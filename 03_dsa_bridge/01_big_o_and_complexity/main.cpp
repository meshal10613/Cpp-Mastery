#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

//? DSA BRIDGE (01. BIG-O COMPLEXITY & TIME LIMITS)
//* Big-O notation describes the upper bound of how execution time or memory
//* scales as input size (N) grows towards infinity.
//*
//* Standard CP/DSA rule of thumb (1-second time limit ≈ 10^8 basic CPU operations):
//* - N <= 10^8 : O(N) or O(log N)
//* - N <= 10^5 : O(N log N) or O(N)
//* - N <= 10^4 : O(N^2)
//* - N <= 500  : O(N^3)
//* - N <= 25   : O(2^N) (Exponential / Backtracking)
//* - N <= 12   : O(N!) (Permutations)

// O(1) Constant Time
int constantTime(const vector<int> &vec)
{
	return vec.empty() ? 0 : vec[0];
}

// O(log N) Logarithmic Time (Binary Search)
int logarithmicTime(const vector<int> &vec, int target)
{
	int low = 0, high = (int)vec.size() - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (vec[mid] == target) return mid;
		if (vec[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

// O(N) Linear Time (Single Pass)
long long linearTime(const vector<int> &vec)
{
	long long sum = 0;
	for (int n : vec) sum += n;
	return sum;
}

// O(N^2) Quadratic Time (Nested Loops)
int quadraticTime(const vector<int> &vec, int limit)
{
	int pairs = 0;
	int n = min((int)vec.size(), limit);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			pairs++;
		}
	}
	return pairs;
}

int main()
{
	cout << "====================================================\n";
	cout << " 01. DSA BRIDGE: BIG-O COMPLEXITY IN ACTION         \n";
	cout << "====================================================\n\n";

	int N = 1000000; // 1 Million elements
	vector<int> data(N);
	for (int i = 0; i < N; i++) data[i] = i * 2;

	cout << "Dataset Size: N = " << N << " elements\n\n";

	// 1. O(1) Benchmark
	auto t1 = high_resolution_clock::now();
	volatile int first = constantTime(data);
	auto t2 = high_resolution_clock::now();
	cout << "O(1) Constant Time:     " 
	     << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds\n";

	// 2. O(log N) Benchmark
	t1 = high_resolution_clock::now();
	volatile int idx = logarithmicTime(data, 1999998);
	t2 = high_resolution_clock::now();
	cout << "O(log N) Binary Search: " 
	     << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds\n";

	// 3. O(N) Benchmark
	t1 = high_resolution_clock::now();
	volatile long long sum = linearTime(data);
	t2 = high_resolution_clock::now();
	cout << "O(N) Linear Scan:       " 
	     << duration_cast<microseconds>(t2 - t1).count() << " microseconds\n";

	// 4. O(N^2) Benchmark (on N = 20,000 to demonstrate steep scaling)
	int smallN = 20000;
	t1 = high_resolution_clock::now();
	volatile int pairs = quadraticTime(data, smallN);
	t2 = high_resolution_clock::now();
	cout << "O(N^2) Nested Loops (N=" << smallN << "): " 
	     << duration_cast<milliseconds>(t2 - t1).count() << " milliseconds\n";

	cout << "\nTakeaway: Scaling from O(log N) to O(N^2) is the difference between microseconds and freezing your CPU!\n";

	return 0;
}

