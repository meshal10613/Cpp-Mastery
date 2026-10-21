#include <iostream>
using namespace std;

class Human
{
public:
	string name;
	int age;
	string occupation;

	void eat()
	{
		cout << name << " is eating!\n";
	}

	void drink()
	{
		cout << "This person is sleeping!\n";
	}
};

int main()
{
	//? Object is a collection of attributes & methods. They can have characteristics & could peform actions. Can be used to mimic real world items(ex. Phone, Book, Dog). Created from a class which acts as a "blue-print"
	Human human1;
	human1.name = "Meshal";
	human1.age = 21;
	human1.occupation = "Software Engineer";

	human1.eat();

	return 0;
}