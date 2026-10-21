#include <iostream>
#include <vector>
using namespace std;

// typedef vector<pair<string, int>> pair_list_t;
// typedef string name_t;

using pair_list_t = vector<pair<string, int>>;
using name_t = string;

int main()
{
	//? typedef is a way to create an alias for a data type, making the code more readable and easier to maintain. In this example, we define two type aliases: `pair_list_t` for a vector of pairs of strings and integers, and `name_t` for a string. It replaces the commented-out typedef declarations with the `using` keyword, which is a more modern and preferred way to create type aliases in C++11 and later.
	pair_list_t my_list = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

	name_t name = "Meshal";

	return 0;
}