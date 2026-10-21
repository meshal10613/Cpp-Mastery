#include<iostream>
using namespace std;

struct students
{
	string name;
	double gpa;
	bool enrolled;
};


int main(){
	//? struct is a structure that group related variables under one name, structs can contain many different data types(string, int, bool, double, etc.), variables in a struct are known as "members", memebers can be access with . "Class Member Access Operator"
	students student1;
	student1.name = "Meshal";
	student1.gpa = 4.89;
	student1.enrolled = true;

	cout << student1.name << endl;
	cout << student1.gpa << endl;
	cout << student1.enrolled << endl;

	return 0;
}