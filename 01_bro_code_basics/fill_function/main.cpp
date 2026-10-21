#include <iostream>
using namespace std;

int main()
{
	//? fill() function is used to fill the entire array with a specific value.
	// fill(begin, end, value)
	string foods[10];
	// {"Pizza", "Burger", "Pasta", "Salad", "Sushi", "Tacos", "Steak", "Ice Cream", "Fries", "Sandwich"};
	fill(foods, foods + 1, "Pizza");
	fill(foods + 1, foods + 2, "Burger");
	for(string food: foods){
		cout << food << endl;
	}

	return 0;
}