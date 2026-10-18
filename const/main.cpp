#include <iostream>
using namespace std;

void printInfo(const string &name, const int &age);

int main()
{
	//? const parameter is a parameter that is effectively read-only. Code is more secure & conveys intent useful for references and pointers
	string name = "Meshal";
	int age = 21;

	printInfo(name, age);

	return 0;
}

void printInfo(const string &name, const int &age)
{
	cout << name << endl;
	cout << age << endl;
}