#include <iostream>
#include <memory>
#include <cstdio> // For FILE*, fopen, fclose

using namespace std;

//? SMART POINTERS (PART 4: RAII & CUSTOM DELETERS)
//* RAII = Resource Acquisition Is Initialization.
//* Fundamental C++ design pattern: Tie the lifecycle of any resource
//* (heap memory, file handles, network sockets, database connections, mutex locks)
//* to the lifetime of a stack object!
//*
//* Custom Deleters:
//* By default, smart pointers call `delete` or `delete[]`.
//* But what if you are managing a C-style `FILE*` that must be closed with `fclose()`?
//* Or a custom Win32/POSIX handle?
//* You can provide a CUSTOM DELETER to unique_ptr and shared_ptr!

// Custom deleter functor for C-style FILE pointer
struct FileCloser
{
	void operator()(FILE *file) const
	{
		if (file)
		{
			cout << "  [Custom Deleter] Closing file safely via fclose()...\n";
			fclose(file);
		}
	}
};

// RAII Wrapper Class demonstration
class ScopedTimer
{
private:
	string operationName;

public:
	ScopedTimer(const string &name) : operationName(name)
	{
		cout << "⏱️  [Timer Started] " << operationName << "\n";
	}

	~ScopedTimer()
	{
		cout << "⏱️  [Timer Ended] " << operationName << " (Resource cleaned up)\n";
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " 04. RAII & CUSTOM DELETERS                         \n";
	cout << "====================================================\n\n";

	//? 1. RAII Scoped Resource Demo
	cout << "--- 1. RAII Scoped Timer ---\n";
	{
		ScopedTimer timer("Database Query Execution");
		// Simulating work
		for (int i = 0; i < 10000000; i++)
		{
			// busy wait
		}
	} // ScopedTimer destructor runs automatically!

	//? 2. Custom Deleter with std::unique_ptr
	cout << "\n--- 2. unique_ptr with Custom File Deleter ---\n";
	{
		// unique_ptr type includes the deleter type: unique_ptr<Type, Deleter>
		unique_ptr<FILE, FileCloser> myFile(fopen("demo_raii.tmp", "w"));

		if (myFile)
		{
			cout << "File opened successfully. Writing data...\n";
			fputs("Hello, RAII in Modern C++!\n", myFile.get());
		}
		cout << "Exiting scope (file will be auto-closed)...\n";
	} // FileCloser functor called automatically!

	// Clean up temporary file
	remove("demo_raii.tmp");

	//? 3. Custom Deleter with std::shared_ptr (Using Lambda!)
	cout << "\n--- 3. shared_ptr with Lambda Deleter ---\n";
	{
		// With shared_ptr, deleter is passed as a constructor argument (no need in template type!)
		shared_ptr<int> customResource(new int(1337), [](int *ptr) {
			cout << "  [Lambda Deleter] Custom cleaning integer resource: " << *ptr << "\n";
			delete ptr;
		});
		cout << "Resource value: " << *customResource << "\n";
	}

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a `LockGuard` class following RAII that prints "Mutex Acquired" in constructor
 *    and "Mutex Released" in destructor.
 * 2. Simulate a critical section inside a block `{ ... }` using your `LockGuard`.
 */
