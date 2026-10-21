#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//? DSA CORE (03. STACKS & QUEUES: MONOTONIC STACK & MIN-STACK)
//* 1. Monotonic Stack:
//*    A stack whose elements are always strictly increasing or decreasing.
//*    Crucial for solving "Next Greater Element", "Daily Temperatures", and "Largest Rectangle in Histogram".
//*
//* 2. Min-Stack:
//*    A stack supporting push, pop, top, and retrieving the minimum element in O(1) constant time!

// 1. Next Greater Element using Monotonic Stack (O(N) time)
vector<int> nextGreaterElement(const vector<int> &nums)
{
	int n = (int)nums.size();
	vector<int> result(n, -1);
	stack<int> st; // Stores indices

	for (int i = 0; i < n; i++)
	{
		// While current element is greater than element represented by stack top
		while (!st.empty() && nums[i] > nums[st.top()])
		{
			result[st.top()] = nums[i];
			st.pop();
		}
		st.push(i);
	}
	return result;
}

// 2. Min-Stack Implementation: All operations O(1)
class MinStack
{
private:
	stack<int> mainStack;
	stack<int> minStack; // Tracks minimum up to each point

public:
	void push(int val)
	{
		mainStack.push(val);
		if (minStack.empty() || val <= minStack.top())
		{
			minStack.push(val);
		}
	}

	void pop()
	{
		if (mainStack.empty()) return;
		if (mainStack.top() == minStack.top())
		{
			minStack.pop();
		}
		mainStack.pop();
	}

	int top()
	{
		return mainStack.top();
	}

	int getMin()
	{
		return minStack.top();
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " 03. DSA CORE: MONOTONIC STACK & MIN-STACK          \n";
	cout << "====================================================\n\n";

	// 1. Next Greater Element Demo
	vector<int> nums = {4, 5, 2, 10, 8};
	vector<int> nge = nextGreaterElement(nums);

	cout << "Original Array:       ";
	for (int n : nums) cout << n << "\t";
	cout << "\nNext Greater Element: ";
	for (int n : nge) cout << n << "\t";
	cout << "\n\n";

	// 2. MinStack Demo
	cout << "MinStack Operations:\n";
	MinStack ms;
	ms.push(10);
	ms.push(20);
	ms.push(5);
	ms.push(15);

	cout << "Current Top: " << ms.top() << " | Current Min: " << ms.getMin() << "\n";
	ms.pop(); // Pop 15
	ms.pop(); // Pop 5
	cout << "After 2 pops -> Current Top: " << ms.top() << " | Current Min: " << ms.getMin() << "\n";

	return 0;
}

