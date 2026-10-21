#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//? DSA CORE (01. ARRAYS & STRINGS: ESSENTIAL PATTERNS)
//* 1. Prefix Sum: O(1) range sum queries after O(N) precomputation.
//* 2. Two Pointers: Left & right pointers moving inward or at different speeds (O(N) instead of O(N^2)).
//* 3. Sliding Window: Maintaining a contiguous subarray/substring window.
//* 4. Kadane's Algorithm: Maximum subarray sum in linear O(N) time.

// 1. Prefix Sum Demonstration
vector<int> buildPrefixSum(const vector<int> &nums)
{
	vector<int> prefix(nums.size() + 1, 0);
	for (size_t i = 0; i < nums.size(); i++)
	{
		prefix[i + 1] = prefix[i] + nums[i];
	}
	return prefix;
}

int queryRangeSum(const vector<int> &prefix, int left, int right)
{
	// Query sum in range [left, right] (0-indexed)
	return prefix[right + 1] - prefix[left];
}

// 2. Two Pointers: Check if string is Palindrome
bool isPalindrome(const string &s)
{
	int left = 0, right = (int)s.length() - 1;
	while (left < right)
	{
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;
}

// 3. Sliding Window: Maximum sum of any subarray of size K
int maxSubarraySumK(const vector<int> &nums, int k)
{
	if ((int)nums.size() < k) return 0;
	int windowSum = 0;
	for (int i = 0; i < k; i++) windowSum += nums[i];

	int maxSum = windowSum;
	for (size_t i = k; i < nums.size(); i++)
	{
		windowSum += nums[i] - nums[i - k]; // Slide window right
		maxSum = max(maxSum, windowSum);
	}
	return maxSum;
}

// 4. Kadane's Algorithm: Maximum Subarray Sum (Handles negatives)
int kadaneMaxSubarray(const vector<int> &nums)
{
	int currentSum = nums[0];
	int maxSum = nums[0];
	for (size_t i = 1; i < nums.size(); i++)
	{
		currentSum = max(nums[i], currentSum + nums[i]);
		maxSum = max(maxSum, currentSum);
	}
	return maxSum;
}

int main()
{
	cout << "====================================================\n";
	cout << " 01. DSA CORE: ARRAYS & STRINGS PATTERNS            \n";
	cout << "====================================================\n\n";

	// 1. Prefix Sum Demo
	vector<int> arr = {2, 4, 1, 7, 3, 5};
	vector<int> prefix = buildPrefixSum(arr);
	cout << "Array: [2, 4, 1, 7, 3, 5]\n";
	cout << "Prefix Sum query [index 1 to 4] (4+1+7+3): " 
	     << queryRangeSum(prefix, 1, 4) << "\n\n";

	// 2. Two Pointers Demo
	string testStr = "racecar";
	cout << "Two Pointers isPalindrome(\"" << testStr << "\"): " 
	     << (isPalindrome(testStr) ? "true" : "false") << "\n\n";

	// 3. Sliding Window Demo
	vector<int> windowData = {2, 1, 5, 1, 3, 2};
	int k = 3;
	cout << "Sliding Window Max Sum (k=" << k << "): " 
	     << maxSubarraySumK(windowData, k) << "\n\n";

	// 4. Kadane's Algorithm Demo
	vector<int> kadaneData = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << "Kadane's Maximum Subarray Sum: " 
	     << kadaneMaxSubarray(kadaneData) << " (Subarray [4, -1, 2, 1])\n";

	return 0;
}

