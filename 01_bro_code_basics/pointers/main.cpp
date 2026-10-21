#include<iostream>
using namespace std;

int main(){
	//? Pointer is a variable that stores memory address of another variable. Sometimes it's easier to work with an address

	//? & address-of operator
	//? * dereference operator
	string name = "Meshal";

	string *pName = &name;

	cout << pName;

	return 0;
}