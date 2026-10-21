#include <iostream>
#include <memory>
#include <string>

using namespace std;

//? SMART POINTERS (PART 3: std::weak_ptr & CIRCULAR REFERENCES)
//* The Circular Dependency (Cycle) Problem:
//* When Object A holds a std::shared_ptr to Object B, AND Object B holds
//* a std::shared_ptr to Object A, their reference counts can NEVER reach 0!
//* Result: A catastrophic MEMORY LEAK where neither object is ever destroyed!
//*
//* The Solution: std::weak_ptr
//* - A weak_ptr is a non-owning observer of a resource managed by shared_ptr.
//* - It does NOT increase the reference count (`use_count()`).
//* - It cannot access the object directly (must call `.lock()` to obtain a temporary shared_ptr).
//* - `.expired()` returns true if the referenced object has already been deleted.

struct Person; // Forward declaration

struct Person
{
	string name;
	//? Using weak_ptr breaks the circular dependency!
	weak_ptr<Person> friendPtr; 

	Person(const string &name) : name(name)
	{
		cout << "  [Person] " << name << " created.\n";
	}

	~Person()
	{
		cout << "  [Person] " << name << " destroyed.\n";
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " 03. SMART POINTERS: std::weak_ptr                  \n";
	cout << "====================================================\n\n";

	//? 1. Circular Reference Prevention Demo
	cout << "--- 1. Breaking Circular References ---\n";
	{
		shared_ptr<Person> alice = make_shared<Person>("Alice");
		shared_ptr<Person> bob = make_shared<Person>("Bob");

		alice->friendPtr = bob; // weak_ptr does NOT increment bob's use_count
		bob->friendPtr = alice; // weak_ptr does NOT increment alice's use_count

		cout << "Alice use_count: " << alice.use_count() << "\n";
		cout << "Bob use_count:   " << bob.use_count() << "\n";
		cout << "Exiting scope -> Both should be cleanly destroyed:\n";
	}
	cout << "Both destroyed successfully without leaks!\n\n";

	//? 2. Accessing weak_ptr using .lock() and .expired()
	cout << "--- 2. Checking .expired() and calling .lock() ---\n";
	weak_ptr<int> weakObservation;

	{
		shared_ptr<int> sharedVal = make_shared<int>(500);
		weakObservation = sharedVal;

		cout << "Inside scope -> Is expired? " << (weakObservation.expired() ? "Yes" : "No") << "\n";

		// Convert weak_ptr to shared_ptr using .lock()
		if (shared_ptr<int> lockedVal = weakObservation.lock())
		{
			cout << "Successfully locked! Observed value: " << *lockedVal << "\n";
		}
	} // sharedVal is destroyed here!

	cout << "Outside scope -> Is expired? " << (weakObservation.expired() ? "Yes" : "No") << "\n";

	if (shared_ptr<int> lockedVal = weakObservation.lock())
	{
		cout << "Observed value: " << *lockedVal << "\n";
	}
	else
	{
		cout << "Could not lock: The object was already destroyed.\n";
	}

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Build a Tree Node structure (`struct Node`).
 * 2. Each parent node owns its children via `std::vector<std::shared_ptr<Node>>`.
 * 3. Each child node points back to its parent using `std::weak_ptr<Node>`.
 * 4. Verify that deleting the root node cleans up the entire tree!
 */

