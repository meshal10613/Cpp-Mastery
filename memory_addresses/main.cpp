#include <iostream>
using namespace std;

void checkAddress(string &name, int &age, bool &isStudent);

int main()
{
	//? Memory address is a location in memory where data is stored, a memory address can accessed with & (address-of operator)

	string name = "Meshal";
	int age = 21;
	bool isStudent = true;

	cout << &name << endl;
	cout << &age << endl;
	cout << &isStudent << endl;

	checkAddress(name, age, isStudent);

	return 0;
}

void checkAddress(string &name, int &age, bool &isStudent)
{
	cout << &name << endl;
	cout << &age << endl;
	cout << &isStudent << endl;
}