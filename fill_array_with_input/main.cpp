#include<iostream>
using namespace std;

int main(){
	//? Fill array with user input
	string foods[5];
	int size = sizeof(foods)/sizeof(string);

	for(int i = 0; i < size; i++){
		cout << "Enter food " << i + 1 << ": ";
		getline(cin, foods[i]);
	}

	for(string food: foods){
		cout << food << endl;
	}

	return 0;
}