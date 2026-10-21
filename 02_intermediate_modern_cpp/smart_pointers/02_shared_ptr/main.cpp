#include <iostream>
#include <memory>
#include <string>

using namespace std;

//? SMART POINTERS (PART 2: std::shared_ptr)
//* std::shared_ptr allows MULTIPLE pointers to share ownership of a single heap resource.
//*
//* Reference Counting:
//* - It maintains an internal "Control Block" that tracks how many shared_ptr instances
//*   are pointing to the resource.
//* - When a new shared_ptr copies an existing one, the reference count INCREMENTS (+1).
//* - When a shared_ptr is destroyed or reset, the reference count DECREMENTS (-1).
//* - When the reference count reaches 0, the managed object is AUTOMATICALLY destroyed!
//*
//* Creation:
//* ALWAYS prefer `std::make_shared<T>(args)` because it allocates the object
//* and control block in a SINGLE contiguous memory allocation (faster and memory-efficient).

class Song
{
public:
	string title;
	string artist;

	Song(const string &t, const string &a) : title(t), artist(a)
	{
		cout << "  [Song Created] \"" << title << "\" by " << artist << "\n";
	}

	~Song()
	{
		cout << "  [Song Destroyed] \"" << title << "\" freed from memory!\n";
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " 02. SMART POINTERS: std::shared_ptr                \n";
	cout << "====================================================\n\n";

	//? 1. CREATING SHARED_PTR & INSPECTING REFERENCE COUNT (.use_count())
	cout << "--- 1. Creating and Sharing Ownership ---\n";
	shared_ptr<Song> playlist1 = make_shared<Song>("Bohemian Rhapsody", "Queen");
	cout << "Initial use count: " << playlist1.use_count() << "\n\n";

	{
		cout << "Entering nested scope...\n";
		shared_ptr<Song> playlist2 = playlist1; // Copying increments ref count!
		cout << "Inside scope: playlist1 use count = " << playlist1.use_count() << "\n";
		cout << "Inside scope: playlist2 use count = " << playlist2.use_count() << "\n";

		shared_ptr<Song> playlist3 = playlist1;
		cout << "After playlist3 added: use count  = " << playlist1.use_count() << "\n";

		cout << "Exiting nested scope...\n";
	} // playlist2 and playlist3 destroyed here. Ref count decrements!

	cout << "Outside scope: playlist1 use count = " << playlist1.use_count() << "\n\n";

	//? 2. RESETTING SHARED_PTR
	cout << "--- 2. Resetting the last shared_ptr ---\n";
	playlist1.reset(); // Ref count drops to 0 -> object destroyed immediately!
	cout << "After reset: playlist1 use count = " << playlist1.use_count() << "\n";

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a `Document` class with a title and content.
 * 2. Create an `Editor` class that holds a `std::shared_ptr<Document>`.
 * 3. Create two `Editor` instances sharing the SAME Document.
 * 4. Verify that edits from one Editor reflect in the other!
 */

