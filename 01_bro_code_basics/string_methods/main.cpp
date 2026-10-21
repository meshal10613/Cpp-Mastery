#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name;

    cout << "Enter you name: ";
    getline(cin >> ws , name);

    cout << "Hello, " << name << endl;

    name.length(); //? returns the length of the string
    
    name.clear(); //? clears the string

    name.empty(); //? returns true if the string is empty

    name.append("Hello"); //? appends a string to the end of the string
    
    name.insert(0, "Hello"); //? inserts a string at a specific position

    name.erase(0, 5); //? erases a part of the string

    name.replace(0, 5, "Hello"); //? replaces a part of the string

    name.substr(0, 5); //? returns a substring

    name.at(0); //? returns the character at a specific position

    name.find("Hello"); //? finds the first occurrence of a character

    name.rfind("Hello"); //? finds the last occurrence of a character

    name.find_first_of("Hello"); //? finds the first occurrence of a character

    name.find_last_of("Hello"); //? finds the last occurrence of a character

    name.find_first_not_of("Hello"); //? finds the first occurrence of a character that is not in the string

    name.find_last_not_of("Hello"); //? finds the last occurrence of a character that is not in the string

    name.size(); //? returns the size of the string

    name.max_size(); //? returns the maximum size of the string

    name.capacity(); //? returns the capacity of the string

    name.reserve(); //? reserves a capacity for the string

    name.shrink_to_fit(); //? shrinks the capacity of the string

    name.resize(5); //? resizes the string

    name.swap(); //? swaps the string with another string

    name.compare(); //? compares the string with another string

    name.c_str(); //? returns the C-style string

    name.data(); //? returns the data of the string

    name.copy(); //? copies the string

	return 0;
}