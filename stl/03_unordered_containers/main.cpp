#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

//? STL (PART 3: UNORDERED CONTAINERS / HASH TABLES)
//* Unordered containers store elements using a HASH TABLE.
//* Elements are NOT sorted in any specific order.
//* 
//* Performance:
//* - Average Case: O(1) constant time for search, insert, and delete!
//* - Worst Case:   O(n) if many hash collisions occur (rare).
//*
//* 1. std::unordered_set<Key>        : Unique elements, hashed, unsorted.
//* 2. std::unordered_map<Key, Value> : Key-Value dictionary, hashed by key, O(1) lookup.
//*
//* When to use std::map vs std::unordered_map?
//* - Use `std::map` when you NEED keys to be sorted in order, or need range queries (lower_bound).
//* - Use `std::unordered_map` when you want maximum raw speed for lookups, insertions, and deletions.

int main()
{
	cout << "====================================================\n";
	cout << " 03. STL UNORDERED CONTAINERS (HASH TABLES)         \n";
	cout << "====================================================\n\n";

	//? 1. std::unordered_set<string>
	cout << "--- 1. std::unordered_set (Fast membership test) ---\n";
	unordered_set<string> bannedUsers = {"troll99", "spammer_bot", "cheater_x"};

	string checkUser = "spammer_bot";
	if (bannedUsers.contains(checkUser))
	{
		cout << "⚠️ User '" << checkUser << "' is BANNED!\n";
	}

	//? 2. REAL-WORLD MINI-PROJECT: Word Frequency Counter using std::unordered_map
	cout << "\n--- 2. Word Frequency Counter (unordered_map) ---\n";
	string text = "c++ is fast c++ is powerful and c++ is fun to learn";
	stringstream ss(text);
	string word;

	unordered_map<string, int> wordCount;

	while (ss >> word)
	{
		wordCount[word]++; // If word doesn't exist, initializes to 0, then increments to 1!
	}

	cout << "Text: \"" << text << "\"\n\nWord Frequencies:\n";
	for (const auto &[w, count] : wordCount)
	{
		cout << "  - " << w << ": " << count << " time(s)\n";
	}

	// Bucket and load factor information
	cout << "\nHash Table Stats:\n";
	cout << "  - Bucket count: " << wordCount.bucket_count() << "\n";
	cout << "  - Load factor:  " << wordCount.load_factor() << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Given an array of integers with duplicates: {4, 5, 2, 4, 7, 2, 9, 5, 4}
 * 2. Use `std::unordered_map<int, int>` to find which number appears the most frequently.
 */

