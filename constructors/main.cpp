#include<iostream>
using namespace std;

class Student{
	public:
		string name;
		int age;
		double gpa;

	Student(string name, int age, double x){
		this->name = name; //? If the attributes name is same as the parameter name, then need to add `this` keyword
		this->age = age;
		gpa = x; //? If the attributes name is different from the parameter name, then don't need to add `this` keyword
	}
};

int main(){
	//? constructors is a special method that is automatically called when an object is instantiated useful for assigning values to attributes as arguments
	Student student1("Meshal", 21, 4.89);
	cout << student1.name << endl;
	cout << student1.age << endl;
	cout << student1.gpa << endl;

	return 0;
}