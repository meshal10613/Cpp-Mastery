#include <iostream>
#include <string>
using namespace std;

void bakePizza()
{
	cout << "Here is your pizza!";
}

void bakePizza(string topping1)
{
	cout << "Here is your " << topping1 << " pizza!";
}

int main()
{
	bakePizza("Cheese");

	return 0;
}