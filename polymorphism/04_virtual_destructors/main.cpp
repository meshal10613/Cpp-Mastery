#include <iostream>

using namespace std;

//? POLYMORPHISM (PART 4: VIRTUAL DESTRUCTORS & MEMORY LEAKS)
//* Why do we need virtual destructors?
//* If you delete a derived class object through a base class pointer:
//* - WITHOUT virtual destructor: Only the Base class destructor is called!
//*   The Derived class destructor is SKIPPED, leading to memory leaks and resource corruption.
//* - WITH virtual destructor: The Derived class destructor is called FIRST,
//*   followed by the Base class destructor.
//*
//* Rule of Thumb: If a class has ANY virtual function, its destructor MUST be virtual!

class BaseBad
{
public:
	BaseBad() { cout << "[BaseBad] Constructor\n"; }
	~BaseBad() { cout << "[BaseBad] Destructor (non-virtual)\n"; }
};

class DerivedBad : public BaseBad
{
private:
	int *heapData;

public:
	DerivedBad()
	{
		heapData = new int[100];
		cout << "  [DerivedBad] Constructor (allocated 100 ints)\n";
	}

	~DerivedBad()
	{
		delete[] heapData;
		cout << "  [DerivedBad] Destructor (freed 100 ints)\n";
	}
};

class BaseGood
{
public:
	BaseGood() { cout << "[BaseGood] Constructor\n"; }

	//? Virtual Destructor ensures polymorphic destruction!
	virtual ~BaseGood() { cout << "[BaseGood] Destructor (virtual)\n"; }
};

class DerivedGood : public BaseGood
{
private:
	int *heapData;

public:
	DerivedGood()
	{
		heapData = new int[100];
		cout << "  [DerivedGood] Constructor (allocated 100 ints)\n";
	}

	~DerivedGood() override
	{
		delete[] heapData;
		cout << "  [DerivedGood] Destructor (freed 100 ints cleanly!)\n";
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " 04. VIRTUAL DESTRUCTORS & MEMORY LEAK PREVENTION   \n";
	cout << "====================================================\n\n";

	cout << "--- SCENARIO 1: Non-Virtual Destructor (BAD) ---\n";
	BaseBad *badPtr = new DerivedBad();
	cout << "Deleting badPtr through BaseBad*...\n";
	delete badPtr; // Notice: DerivedBad destructor is NEVER called! Leak!

	cout << "\n----------------------------------------------------\n";
	cout << "--- SCENARIO 2: Virtual Destructor (GOOD) ---\n";
	BaseGood *goodPtr = new DerivedGood();
	cout << "Deleting goodPtr through BaseGood*...\n";
	delete goodPtr; // Both DerivedGood and BaseGood destructors run! Clean!

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a class `DatabaseConnection` with virtual destructor.
 * 2. Create `PostgresConnection` which allocates a dynamic buffer in its constructor.
 * 3. Store a `PostgresConnection` in a `DatabaseConnection*` and safely delete it.
 */

