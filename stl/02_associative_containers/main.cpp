#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

//? STL (PART 2: ASSOCIATIVE CONTAINERS)
//* Associative containers store elements in a SORTED order based on keys.
//* Implementation: Self-balancing Binary Search Trees (Red-Black Trees).
//* Search, Insert, and Delete operations have O(log n) logarithmic time complexity.
//*
//* 1. std::set<Key>            : Stores UNIQUE elements in sorted order.
//* 2. std::multiset<Key>       : Stores DUPLICATE elements in sorted order.
//* 3. std::map<Key, Value>     : Stores Key-Value pairs with UNIQUE keys sorted by key.
//* 4. std::multimap<Key, Value>: Stores Key-Value pairs with DUPLICATE keys allowed.

int main()
{
	cout << "====================================================\n";
	cout << " 02. STL ASSOCIATIVE CONTAINERS (SET & MAP)         \n";
	cout << "====================================================\n\n";

	//? 1. std::set<int> (Sorted, Unique Keys)
	cout << "--- 1. std::set<int> (Unique & Automatically Sorted) ---\n";
	set<int> uniqueNumbers = {50, 10, 30, 20, 10, 50, 40}; // Duplicates ignored!

	uniqueNumbers.insert(25);
	uniqueNumbers.insert(10); // Duplicate! Will not be inserted.

	cout << "Set contents: ";
	for (int n : uniqueNumbers) cout << n << " ";
	cout << "\n";

	// Checking existence using .contains() (C++20/C++23) or .count()
	if (uniqueNumbers.contains(25))
	{
		cout << "25 is present in the set!\n";
	}

	//? 2. std::map<string, double> (Key-Value Dictionary)
	cout << "\n--- 2. std::map<string, double> (Product Catalog) ---\n";
	map<string, double> inventory;

	// Insertion methods:
	inventory["Laptop"] = 999.99;
	inventory["Mouse"] = 25.50;
	inventory["Keyboard"] = 75.00;
	inventory.insert({"Monitor", 189.90});

	// Updating value
	inventory["Mouse"] = 29.99;

	// Iterating through map (keys are sorted alphabetically)
	for (const auto &[item, price] : inventory)
	{
		cout << "  - " << item << " : $" << price << "\n";
	}

	// Finding an element
	string searchItem = "Keyboard";
	auto it = inventory.find(searchItem);
	if (it != inventory.end())
	{
		cout << "\nFound " << searchItem << "! Price: $" << it->second << "\n";
	}

	//? 3. std::multiset<int> (Sorted, allows duplicates)
	cout << "\n--- 3. std::multiset<int> (Allows duplicates) ---\n";
	multiset<int> scores = {90, 85, 90, 70, 85};
	scores.insert(90);

	cout << "Multiset scores: ";
	for (int s : scores) cout << s << " ";
	cout << "\nNumber of students with score 90: " << scores.count(90) << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a `std::map<string, int>` representing a phonebook (Name -> Phone Number).
 * 2. Add 3 contacts.
 * 3. Search for a contact by name and print their phone number. If not found, display a warning.
 */

