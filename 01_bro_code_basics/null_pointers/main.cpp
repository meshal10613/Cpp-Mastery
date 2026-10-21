#include <iostream>
using namespace std;

int main()
{
	//? NULL value is a special value that means something has no value. When a pointer is holding a null value, that pointer is not pointing at anything(null pointer)

	//? nullptr is the keyword that represents a null pointer literal. nullptrs are helpfull when determining if an address was successfully assigned to a pointer

	int *pointer = nullptr;
	int x = 123;

	pointer = &x;
	if (pointer == nullptr)
	{
		cout << "address wasn't assigned!\n";
	}
	else
	{
		cout << "address was assigned!\n";
		cout << *pointer;
	}

	return 0;
}