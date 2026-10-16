#include<iostream>
using namespace std;

namespace first{
	int x = 10;
}

namespace second{
	int a = 20;
}

int main() {
	//? Namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it. Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries.
	int x;
	using namespace second;

	cout << first::x << endl;
	cout << a << endl;

	return 0;
}