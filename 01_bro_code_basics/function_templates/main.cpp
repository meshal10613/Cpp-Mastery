#include <iostream>
using namespace std;

template <typename T, typename U>
auto max(T x, U y)
{
	return (x > y) ? x : y;
}

int main()
{
	//? Function Templates describes what a function looks like. Can be used to generate overloaded functions as needed, each using different data types
	cout << max(1, 2.10) << endl;

	return 0;
}
