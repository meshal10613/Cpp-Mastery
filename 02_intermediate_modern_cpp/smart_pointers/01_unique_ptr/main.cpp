#include <iostream>
#include <memory>
#include <string>

using namespace std;

//? SMART POINTERS (PART 1: std::unique_ptr)
//* Introduced in C++11 (<memory>), smart pointers automate memory management.
//* They follow the RAII principle (Resource Acquisition Is Initialization):
//* When a smart pointer goes out of scope, it AUTOMATICALLY deletes the heap memory!
//* No manual `delete` needed -> No memory leaks!
//*
//* std::unique_ptr:
//* - EXCLUSIVE OWNERSHIP: Only ONE unique_ptr can own a given object on the heap at any time.
//* - Cannot be COPIED (copy constructor is deleted).
//* - Can be MOVED using std::move() (ownership is transferred).
//* - Creation: ALWAYS prefer `std::make_unique<T>(args)` (C++14+) over `new`.

class Entity
{
private:
	string name;

public:
	Entity(const string &name) : name(name)
	{
		cout << "  [Entity] Created: " << name << "\n";
	}

	~Entity()
	{
		cout << "  [Entity] Destroyed: " << name << " (automatic cleanup!)\n";
	}

	void speak() const
	{
		cout << "  " << name << " says: Hello from heap memory!\n";
	}
};

void takeOwnership(unique_ptr<Entity> entity)
{
	cout << "Inside takeOwnership function:\n";
	entity->speak();
	// When function ends, entity goes out of scope and is deleted right here!
}

int main()
{
	cout << "====================================================\n";
	cout << " 01. SMART POINTERS: std::unique_ptr                \n";
	cout << "====================================================\n\n";

	//? 1. CREATING A UNIQUE_PTR
	cout << "--- 1. Creating unique_ptr with std::make_unique ---\n";
	{
		unique_ptr<Entity> e1 = make_unique<Entity>("Alpha");
		e1->speak();
		cout << "Exiting inner scope now...\n";
	} // e1 goes out of scope HERE and is automatically destroyed!
	cout << "Outside inner scope.\n\n";

	//? 2. OWNERSHIP TRANSFER VIA std::move
	cout << "--- 2. Moving Ownership (std::move) ---\n";
	unique_ptr<Entity> source = make_unique<Entity>("Beta");

	// unique_ptr<Entity> copy = source; // ❌ COMPILER ERROR: unique_ptr cannot be copied!
	unique_ptr<Entity> destination = move(source); // Ownership transferred!

	if (source == nullptr)
	{
		cout << "source pointer is now nullptr (ownership moved successfully).\n";
	}

	destination->speak();

	//? 3. PASSING UNIQUE_PTR TO FUNCTIONS
	cout << "\n--- 3. Passing to Function by Move ---\n";
	takeOwnership(move(destination));

	if (destination == nullptr)
	{
		cout << "destination is now nullptr (ownership was consumed by takeOwnership).\n";
	}

	//? 4. USEFUL MEMBER FUNCTIONS (.get(), .reset(), .release())
	cout << "\n--- 4. Member Functions (.get, .reset, .release) ---\n";
	unique_ptr<int> numPtr = make_unique<int>(42);

	// .get() returns the raw pointer without transferring ownership
	int *raw = numPtr.get();
	cout << "Raw pointer value: " << *raw << "\n";

	// .reset() deletes old object and resets to new or nullptr
	numPtr.reset(new int(99));
	cout << "After reset, new value: " << *numPtr << "\n";

	// .release() releases ownership without deleting (you become responsible for deleting)
	int *abandoned = numPtr.release();
	cout << "Released value: " << *abandoned << " (remember to manually delete!)\n";
	delete abandoned; // Must manually delete released memory

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a `Player` class with `name` and `score`.
 * 2. Write a function `createPlayer(string name)` that returns a `std::unique_ptr<Player>`.
 * 3. Store 3 players inside a `std::vector<std::unique_ptr<Player>>` using `push_back(std::move(...))`.
 */

