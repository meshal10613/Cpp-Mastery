#include <iostream>
#include <vector>

using namespace std;

//? DSA CORE (04. BINARY SEARCH VARIANTS & MERGE SORT)
//* 1. Standard Binary Search: O(log N) search on sorted arrays.
//* 2. Lower Bound: Finds the FIRST index where value >= target.
//* 3. Merge Sort: Classic divide-and-conquer O(N log N) stable sorting algorithm.

// 1. Binary Search (Overflow-safe mid calculation)
int binarySearch(const vector<int> &nums, int target)
{
	int low = 0, high = (int)nums.size() - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2; // Prevents integer overflow!
		if (nums[mid] == target) return mid;
		if (nums[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

// 2. Custom Lower Bound Implementation
int customLowerBound(const vector<int> &nums, int target)
{
	int low = 0, high = (int)nums.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid; // Candidate found, check left half
		}
	}
	return low;
}

// 3. Merge Sort Implementation
void merge(vector<int> &arr, int left, int mid, int right)
{
	vector<int> temp;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
		else temp.push_back(arr[j++]);
	}

	while (i <= mid) temp.push_back(arr[i++]);
	while (j <= right) temp.push_back(arr[j++]);

	for (size_t k = 0; k < temp.size(); k++)
	{
		arr[left + k] = temp[k];
	}
}

void mergeSort(vector<int> &arr, int left, int right)
{
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int main()
{
	cout << "====================================================\n";
	cout << " 04. DSA CORE: BINARY SEARCH & MERGE SORT           \n";
	cout << "====================================================\n\n";

	vector<int> data = {38, 27, 43, 3, 9, 82, 10};
	cout << "Unsorted array: ";
	for (int n : data) cout << n << " ";
	cout << "\n";

	mergeSort(data, 0, (int)data.size() - 1);

	cout << "Sorted array:   ";
	for (int n : data) cout << n << " ";
	cout << "\n\n";

	// Binary Search Tests
	int target = 27;
	cout << "binarySearch for " << target << " found at index: " 
	     << binarySearch(data, target) << "\n";

	int searchVal = 20;
	int lbIdx = customLowerBound(data, searchVal);
	cout << "customLowerBound for " << searchVal << ": index " 
	     << lbIdx << " (value: " << data[lbIdx] << ")\n";

	return 0;
}

