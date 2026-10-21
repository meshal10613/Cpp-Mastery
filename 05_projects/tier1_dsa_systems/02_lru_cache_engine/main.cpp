#include <iostream>
#include <unordered_map>
#include <list>
#include <optional>
#include <string>

using namespace std;

//? PROJECT 02: LRU CACHE ENGINE (STARTER SKELETON)
//* Follow the TODOs below to implement your high-performance LRU Cache!

template <typename K, typename V>
class LRUCache
{
private:
	size_t capacity;
	// Doubly linked list storing pairs of (Key, Value)
	list<pair<K, V>> dll;
	// Hash map storing key -> iterator to list node
	unordered_map<K, typename list<pair<K, V>>::iterator> cacheMap;

public:
	LRUCache(size_t capacity) : capacity(capacity) {}

	// TODO: Step 1 - Implement get(key) in O(1) time
	optional<V> get(const K &key)
	{
		// TODO: Check if key exists in cacheMap
		// If found: move node to front of dll, return value
		// If not found: return nullopt
		return nullopt;
	}

	// TODO: Step 2 - Implement put(key, value) in O(1) time
	void put(const K &key, const V &value)
	{
		// TODO: If key already exists, update value and move to front
		// TODO: If key is new:
		//       - Check if capacity is reached -> evict least recently used (tail of dll)
		//       - Insert new node at front of dll
		//       - Update cacheMap
	}

	// TODO: Step 3 - Utility to display current cache state
	void printCache() const
	{
		cout << "Cache Contents (Head to Tail): ";
		for (const auto &[k, v] : dll)
		{
			cout << "[" << k << ": " << v << "] ";
		}
		cout << "\n";
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " PROJECT 02: LRU CACHE ENGINE SKELETON              \n";
	cout << "====================================================\n\n";

	LRUCache<string, int> cache(3); // Capacity = 3

	cout << "Cache created with capacity = 3.\n";
	cout << "Ready for implementation! Follow the instructions in README.md.\n";

	return 0;
}

