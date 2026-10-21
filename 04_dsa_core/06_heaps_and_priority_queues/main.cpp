#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

//? DSA CORE (06. HEAPS & PRIORITY QUEUES)
//* A Binary Heap is a complete binary tree satisfying the Heap Property:
//* - Max-Heap: Parent >= Children (root is always maximum). Default in C++ std::priority_queue.
//* - Min-Heap: Parent <= Children (root is always minimum). Defined with std::greater<T>.
//*
//* Core Patterns:
//* 1. Top-K Elements / Kth Largest in O(N log K) time using a Min-Heap of size K!
//* 2. Custom Comparator Priority Queue for scheduling and Dijkstra algorithms.

// Kth Largest Element using Min-Heap of size K
int findKthLargest(const vector<int> &nums, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int num : nums)
	{
		minHeap.push(num);
		if ((int)minHeap.size() > k)
		{
			minHeap.pop(); // Remove smallest so heap only keeps K largest
		}
	}
	return minHeap.top();
}

// Custom Struct with Comparator
struct Task
{
	string name;
	int priority; // Higher number = more urgent
	int durationMinutes;
};

// Comparator: Returns true if t1 should come AFTER t2
struct CompareTask
{
	bool operator()(const Task &t1, const Task &t2)
	{
		return t1.priority < t2.priority; // Highest priority at top
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " 06. DSA CORE: HEAPS & PRIORITY QUEUES              \n";
	cout << "====================================================\n\n";

	// 1. Kth Largest Element Demo
	vector<int> nums = {3, 2, 1, 5, 6, 4};
	int k = 2;
	cout << "Array: [3, 2, 1, 5, 6, 4]\n";
	cout << k << "-th Largest Element: " << findKthLargest(nums, k) << "\n\n";

	// 2. Custom Priority Queue Demo
	cout << "--- Custom Task Scheduler (Priority Queue) ---\n";
	priority_queue<Task, vector<Task>, CompareTask> taskScheduler;

	taskScheduler.push({"Send Daily Report", 2, 15});
	taskScheduler.push({"Fix Server Outage", 10, 60});
	taskScheduler.push({"Respond to Email", 1, 5});
	taskScheduler.push({"Database Migration", 8, 45});

	while (!taskScheduler.empty())
	{
		Task topTask = taskScheduler.top();
		taskScheduler.pop();
		cout << "Executing: [" << topTask.name 
		     << "] (Priority: " << topTask.priority 
		     << ", Duration: " << topTask.durationMinutes << " mins)\n";
	}

	return 0;
}

