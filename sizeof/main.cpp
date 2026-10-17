#include<iostream>
using namespace std;

int main(){
	//? sizeof is determines the size in bytes of a: variable, data type, class, objects, etc.
	string name = "Meshal"; // size 32
	double gpa = 2.5; // size 8
	char grade = 'A'; // size 1
	bool isStudent = true; // size 1
	char grades[] = {'A', 'B', 'C', 'D'}; // size count the values(4)

	// cout << sizeof(grades);

	string students[] = {"Meshal", "Rupom", "Faysal", "Muhib"};
	// the size/ length of this array should be
	cout << sizeof(students)/sizeof(string); //* 4

	return 0;
}