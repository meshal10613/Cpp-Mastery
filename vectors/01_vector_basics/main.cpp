#include <iostream>
#include <vector>
#include <string>

using namespace std;

//? VECTORS (PART 1: BASICS & CAPACITY)
//* A std::vector is a dynamic array from the Standard Template Library (STL).
//* Unlike traditional C++ arrays (which have fixed size), vectors can grow and shrink in size dynamically.
//* Vectors manage their own memory automatically on the heap while providing contiguous storage.

int main()
{
	cout << "========================================\n";
	cout << "    01. C++ VECTORS: BASICS & SIZING    \n";
	cout << "========================================\n\n";

	//? 1. DECLARATION & INITIALIZATION
	vector<int> emptyVec;                        // Empty vector of ints
	vector<int> nums = {10, 20, 30, 40, 50};     // Initializer list
	vector<string> names(3, "Unknown");          // 3 elements, each initialized to "Unknown"
	vector<int> copyNums(nums);                  // Copy of nums

	//? 2. ACCESSING ELEMENTS
	//* - operator[] : Fast access, NO bounds checking (can cause undefined behavior if out of range)
	//* - .at(index) : Safe access WITH bounds checking (throws std::out_of_range exception)
	//* - .front()   : Returns reference to first element
	//* - .back()    : Returns reference to last element
	//* - .data()    : Direct pointer to the underlying array

	cout << "--- Element Access ---\n";
	cout << "First element (using [0]): " << nums[0] << "\n";
	cout << "Second element (.at(1)):   " << nums.at(1) << "\n";
	cout << "First element (.front()):  " << nums.front() << "\n";
	cout << "Last element (.back()):    " << nums.back() << "\n";

	// Safe bounds checking demo:
	try
	{
		cout << nums.at(10); // Out of bounds!
	}
	catch (const out_of_range &e)
	{
		cout << "Caught expected exception with .at(10): " << e.what() << "\n";
	}

	//? 3. SIZE VS CAPACITY (CRITICAL CONCEPT!)
	//* - size()     : Number of elements currently stored in the vector.
	//* - capacity() : Total elements the vector can hold BEFORE needing to reallocate memory.
	//* When size exceeds capacity, the vector automatically allocates a larger block of memory (usually 1.5x or 2x)
	//* and moves elements over.

	cout << "\n--- Size vs Capacity Growth ---\n";
	vector<int> dynamicGrowth;

	for (int i = 1; i <= 8; i++)
	{
		dynamicGrowth.push_back(i * 10);
		cout << "Added " << i * 10 
		     << " | Size: " << dynamicGrowth.size() 
		     << " | Capacity: " << dynamicGrowth.capacity() << "\n";
	}

	//? 4. CAPACITY OPTIMIZATIONS
	//* - reserve(n)      : Pre-allocates memory for at least n elements (avoids repeated reallocations)
	//* - shrink_to_fit() : Reduces memory capacity to fit its current size
	//* - empty()         : Returns true if size == 0

	cout << "\n--- Capacity Optimization ---\n";
	vector<int> reservedVec;
	reservedVec.reserve(100); // Reserve memory upfront for 100 items!
	cout << "Reserved vector size: " << reservedVec.size() 
	     << ", capacity: " << reservedVec.capacity() << "\n";

	reservedVec.push_back(1);
	reservedVec.push_back(2);
	cout << "After 2 items -> size: " << reservedVec.size() 
	     << ", capacity: " << reservedVec.capacity() << "\n";

	reservedVec.shrink_to_fit();
	cout << "After shrink_to_fit() -> size: " << reservedVec.size() 
	     << ", capacity: " << reservedVec.capacity() << "\n";

	//? 5. ITERATING THROUGH A VECTOR
	cout << "\n--- Iteration (Range-based for loop) ---\n";
	for (const string &name : names)
	{
		cout << name << " ";
	}
	cout << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a vector of doubles representing item prices in a shopping cart.
 * 2. Pre-allocate memory using .reserve() for 5 items.
 * 3. Add 5 prices, print the sum and average price.
 * 4. Print whether the cart is empty using .empty().
 */

