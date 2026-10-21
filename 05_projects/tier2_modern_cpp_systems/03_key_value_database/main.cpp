#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include <expected>
#include <sstream>
#include <vector>

using namespace std;
using namespace std::chrono;

//? PROJECT 03: IN-MEMORY KEY-VALUE DATABASE (MINI-REDIS)
//* Follow the TODOs below to implement your Key-Value store!

struct ValueEntry
{
	string value;
	time_point<steady_clock> expiryTime;
	bool hasExpiry = false;

	bool isExpired() const
	{
		if (!hasExpiry) return false;
		return steady_clock::now() > expiryTime;
	}
};

class KeyValueStore
{
private:
	unordered_map<string, ValueEntry> store;

public:
	// TODO: Step 1 - Implement set(key, value, optional ttlSeconds)
	void set(const string &key, const string &val, int ttlSeconds = -1)
	{
		ValueEntry entry;
		entry.value = val;
		if (ttlSeconds > 0)
		{
			entry.hasExpiry = true;
			entry.expiryTime = steady_clock::now() + seconds(ttlSeconds);
		}
		store[key] = entry;
	}

	// TODO: Step 2 - Implement get(key) with expiration check using std::expected (C++23)
	expected<string, string> get(const string &key)
	{
		auto it = store.find(key);
		if (it == store.end())
		{
			return unexpected("Key not found");
		}
		if (it->second.isExpired())
		{
			store.erase(it); // Lazy eviction
			return unexpected("Key has expired");
		}
		return it->second.value;
	}

	// TODO: Step 3 - Implement del(key)
	bool del(const string &key)
	{
		return store.erase(key) > 0;
	}

	// TODO: Step 4 - Implement persistence to disk (Save / Load WAL)
	void saveToDisk(const string &filePath)
	{
		// TODO: Write store entries to file
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " PROJECT 03: KEY-VALUE STORE REPL SKELETON          \n";
	cout << "====================================================\n";
	cout << "Supported commands: SET <key> <val> [EX sec] | GET <key> | DEL <key> | EXIT\n\n";

	KeyValueStore db;
	cout << "Ready for implementation! Follow the instructions in README.md.\n";

	return 0;
}

