#include <iostream>
using namespace std;

class Animal
{
public:
	bool alive = true;

	void eat()
	{
		cout << "This animal is eating!\n";
	}
};

class Dog : public Animal
{
public:
	void bark()
	{
		cout << "The dog goes woof!\n";
	}
};

int main()
{
	//? Inheritance is a class can recieve & methods from another class children classes inherit from a parent class. Helps to reuse similar code found within multiple classes
	Dog dog1;
	dog1.eat();

	return 0;
}