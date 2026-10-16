#include<iostream>
using namespace std;

int main() {
	//? User input is taken using cin and stored in a variable

	string name;

	cout << "Enter your name: ";
	getline(cin >> ws, name); //? Use getline to read a full line of input, including spaces and ws to ignore any leading whitespace

	cout << "Hello, " << name << "!" << endl;

	return 0;
}