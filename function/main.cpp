#include<iostream>
#include<string>
using namespace std;

string birthday(string name){
	return "Happy Birthday " + name + "!";
}

int main(){
	//? Function is a block of reusable code!
	string message = birthday("Meshal");
	cout << message;

	return 0;
}